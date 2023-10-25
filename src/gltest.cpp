#include "glad/glad.h"

#include <GLFW/glfw3.h>

#include <iostream>

#include "utils/utils.h"
#include "Shader/Shader.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


int main() {
    // Setup GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //GLFWmonitor* run_monitor = pick_monitor();

    //const GLFWvidmode* current_video_mode = glfwGetVideoMode(run_monitor);
    //std::cout << "Detected resolution: " << current_video_mode->width << "x" << current_video_mode->height << std::endl;
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "gltest", NULL, NULL);
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
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Set resize callback
    glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);

    // Set keyboard callback
    glfwSetKeyCallback(window, input_callback);

    Shader orange_shader("triangle_vertex.shader", "orange.shader");
    Shader green_shader("triangle_vertex.shader", "green.shader");

    float orange_verticies [] = {
        -1.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        -0.5f, 0.0f, 0.0f,
    };

    float green_verticies[] = {
        0.0f, 0.0f, 0.0f,
        0.5f, 1.0f, 0.0f,
        1.0f, 0.0f, 0.0f
    };

    GLuint orange_vao;
    glGenVertexArrays(1, &orange_vao);

    GLuint orange_vbo;
    glGenBuffers(1, &orange_vbo);


    GLuint green_vao;
    glGenVertexArrays(1, &green_vao);

    GLuint green_vbo;
    glGenBuffers(1, &green_vbo);

    // Bind to the vao and vbo of the first triangle
    glBindVertexArray(orange_vao);
    glBindBuffer(GL_ARRAY_BUFFER, orange_vbo);
    // Place the data into the array buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(orange_verticies), orange_verticies, GL_STATIC_DRAW);
    // Set vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    // Enable the array
    glEnableVertexAttribArray(0);

    // Bind to vao and vbo of second triangle
    glBindVertexArray(green_vao);
    glBindBuffer(GL_ARRAY_BUFFER, green_vbo);
    // Place data into array buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(green_verticies), green_verticies, GL_STATIC_DRAW);
    // Set Vertex attributes again
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    // enable array
    glEnableVertexAttribArray(0);

    // Unbind from any vao
    glBindVertexArray(0);


    // Render loop
    while(!glfwWindowShouldClose(window)) {
        //handle_input(window);

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        orange_shader.use();

        // bind to and draw first triangle
        glBindVertexArray(orange_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        green_shader.use();
        // bind to and draw second triangle
        glBindVertexArray(green_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
