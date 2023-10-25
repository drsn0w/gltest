#pragma once

#include <GLFW/glfw3.h>

void handle_input(GLFWwindow* window);
void framebuffer_resize_callback(GLFWwindow* window, int width, int height);
void input_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
GLFWmonitor* pick_monitor();
