#include "glad/glad.h"

#include <GLFW/glfw3.h>

#include <iostream>

#include "utils/utils.h"
#include "Shader/Shader.h"


int main() {
    // Setup GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWmonitor* run_monitor = pick_monitor();

    const GLFWvidmode* current_video_mode = glfwGetVideoMode(run_monitor);
    std::cout << "Detected resolution: " << current_video_mode->width << "x" << current_video_mode->height << std::endl;
    GLFWwindow* window = glfwCreateWindow(current_video_mode->width, current_video_mode->height, "gltest", run_monitor, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create window!" << std::endl;
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);

    // Check to make sure GLAD loaded
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD!" << std::endl;
        return EXIT_FAILURE;
    }

    // Set viewport of window
    glViewport(0, 0, current_video_mode->width, current_video_mode->height);

    // Set resize callback
    glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);

    Shader triangle_shader("testshader.vs", "testshader.fs");

    float verticies [] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);




    // Render loop
    while(!glfwWindowShouldClose(window)) {
        handle_input(window);

        triangle_shader.use();
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}