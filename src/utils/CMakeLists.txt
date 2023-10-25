add_library(gltesterutils STATIC utils.cpp)

target_include_directories(gltesterutils PUBLIC ${CMAKE_SOURCE_DIR}/inc)

target_link_libraries(gltesterutils PkgConfig::GL PkgConfig::GLFW)