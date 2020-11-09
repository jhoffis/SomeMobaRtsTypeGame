#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "Window.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

GLFWwindow* window;
bool framebufferResized = false;

static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
//    auto app = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
//    app->
    framebufferResized = true;
}

void Window::initWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

void destroy() {
    glfwDestroyWindow(window);

    glfwTerminate();
}