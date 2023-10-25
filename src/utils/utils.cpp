#include <utils/utils.h>

#include <GLFW/glfw3.h>

#include <iostream>

void handle_input(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        std::cout << "Got ESC!" << std::endl;
        glfwSetWindowShouldClose(window, true);
    };
}

void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void input_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(action == GLFW_PRESS) {
        switch(key) {
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, true);
                break;
            case GLFW_KEY_2:
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                break;
            case GLFW_KEY_1:
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                break;
        }
    }
}

GLFWmonitor* pick_monitor() {
    int monitor_count;
    GLFWmonitor** monitors = glfwGetMonitors(&monitor_count);
    if(monitor_count == 0) {
        std::cerr << "ERROR: Failed to enumerate monitors!" << std::endl;
    }
    std::cout << "Detected " << monitor_count << " monitors: " << std::endl;
    for(int i = 0; i < monitor_count; i++) {
        int width = glfwGetVideoMode(monitors[i])->width;
        int height = glfwGetVideoMode(monitors[i])->height;
        std::cout << i+1 << ". " << width << "x" << height << std::endl;
    }

    std::cout << "Use which monitor? ";
    int x;
    std::cin >> x;


    return monitors[x-1];
}
