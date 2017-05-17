cmake_minimum_required(VERSION 2.6)
project(Tutorial)

option(USE_MYMATH "Use my implementation" ON)

set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)
configure_file(
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
    )

include_directories("${PROJECT_BINARY_DIR}")

if(USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunction")
    add_subdirectory(MathFunction)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunction)
endif(USE_MYMATH)

add_executable(Tutorial tutorial.cpp)
target_link_libraries(Tutorial ${EXTRA_LIBS})
