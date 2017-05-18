#1.version and project name should be named
cmake_minimum_required(VERSION 2.6)
project(Tutorial)


#8.check System Introspection
include(${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists(log HEVC_LOG)
check_function_exists(exp HEVC_EXP)

#2.options
option(USE_MYMATH "Use my implementation" ON)

#3.configure_files
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)
configure_file(
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
    )

#4.subdirectories
include_directories("${PROJECT_BINARY_DIR}")
if(USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunction")
    add_subdirectory(MathFunction)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunction)
endif(USE_MYMATH)

#5.add targets and name the link libraries
add_executable(Tutorial tutorial.cpp)
target_link_libraries(Tutorial ${EXTRA_LIBS})

#6.make install options
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

#7.add tests
enable_testing()

add_test(TutorialRun Tutorial 25)

add_test(TutorialUsage Tutorial)
set_tests_properties(TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "dasd")

macro(do_test arg result)
    add_test(TutorialComp${arg} Tutorial ${arg})
    set_tests_properties(TutorialComp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)
do_test(25 "25 is 5")
do_test(-25 "-25 is 0")
do_test(0.0001 "0.0001 is 0.01")


