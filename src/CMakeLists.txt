add_executable(gltest gltest.cpp utils/utils.cpp)

target_include_directories(gltest PUBLIC ${CMAKE_SOURCE_DIR}/inc)

add_subdirectory(glad)
add_subdirectory(utils)
add_subdirectory(Shader)

target_link_libraries(gltest glad Shader PkgConfig::GL PkgConfig::GLFW)