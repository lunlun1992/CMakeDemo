include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_library(MathFunction mysqrt.cpp)
install(TARGETS MathFunction DESTINATION bin)
install(FILES MathFunction.h DESTINATION include)

