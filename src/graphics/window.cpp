//
// Created by heasummn on 8/15/16.
//

#include <GL/glew.h>
#include <iostream>
#include "window.h"

using namespace engine::graphics;

Window::Window(const char *name, int width, int height)
{
    _name = name;
    _width = width;
    _height = height;

    if(!init())
        glfwTerminate();
}

bool Window::init()
{
    if(!glfwInit())
    {
        std::cout << "Failed to initialize GLFW and its components" << std::endl;
        return false;
    }
    _window = glfwCreateWindow(_width, _height, _name, nullptr, nullptr);
    if(!_window)
    {
        std::cout << "Failed to create GLFW Window Context" << std::endl;
        glfwDestroyWindow(_window);
        return false;
    }
    glfwMakeContextCurrent(_window);
    glfwSetWindowPosCallback(_window, resizeHandler);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        std::cout << "Initialization of GLEW failed with " << glewGetErrorString(err) << std::endl;
    }

    return true;
}

void Window::tick()
{
    // Check for events
    glfwPollEvents();
    glfwSwapBuffers(_window);

    // Set the Window Size, since we can't do this in the resize handler
    // TODO: Check how much time this takes, and if it is worth it.
    glfwGetWindowSize(_window, &_width, &_height);
}

void Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::resizeHandler(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

bool Window::closed() {
    return glfwWindowShouldClose(_window) == GLFW_TRUE;
}

void Window::close() {
    glfwSetWindowShouldClose(_window, true);
}
