file(GLOB glsl_files *.glsl)

foreach(glsl_file ${glsl_files})
    configure_file(${glsl_file} ${CMAKE_BINARY_DIR}/src/)
endforeach()
