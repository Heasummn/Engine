#include <GLFW/glfw3.h>
#include <iostream>

int main(int argc, char* argv[])
{
    if(!glfwInit())
    {
        std::cout << "Initialization of GLFW failed" << std::endl;
    }

    // Initialize the window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow* window = glfwCreateWindow(640, 480, "The Most creatively named Game Engine ever", nullptr, nullptr);
    if(!window)
    {
        std::cout << "Creation of Window or OpenGL context failed" << std::endl;
    }

    while (!glfwWindowShouldClose(window))
    {
        // Keep running
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}