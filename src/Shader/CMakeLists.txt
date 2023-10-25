add_library(Shader STATIC Shader.cpp)

target_include_directories(Shader PUBLIC ${CMAKE_SOURCE_DIR}/inc)