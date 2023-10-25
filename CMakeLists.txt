cmake_minimum_required(VERSION 3.0.0)

project(gltest VERSION 0.0.1 LANGUAGES C CXX)


# Check for glfw3
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED IMPORTED_TARGET glfw3)
pkg_check_modules(GL REQUIRED IMPORTED_TARGET gl)

add_subdirectory(src)

configure_file(orange.shader ${CMAKE_BINARY_DIR}/src/orange.shader)
configure_file(triangle_vertex.shader ${CMAKE_BINARY_DIR}/src/triangle_vertex.shader)
configure_file(green.shader ${CMAKE_BINARY_DIR}/src/green.shader)
