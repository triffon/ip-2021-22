cmake_minimum_required(VERSION 3.0.0)
project(functions VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(functions main.cpp io.cpp triangle.cpp geometry.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
