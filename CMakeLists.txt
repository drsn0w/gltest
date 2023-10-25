cmake_minimum_required(VERSION 3.0.0)

project(gltest VERSION 0.0.1 LANGUAGES C CXX)


# Check for glfw3
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED IMPORTED_TARGET glfw3)
pkg_check_modules(GL REQUIRED IMPORTED_TARGET gl)

add_subdirectory(src)

configure_file(testshader.fs ${CMAKE_BINARY_DIR}/src/testshader.fs)
configure_file(testshader.vs ${CMAKE_BINARY_DIR}/src/testshader.vs)