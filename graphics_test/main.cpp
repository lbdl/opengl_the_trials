//
//  main.cpp
//  graphics_test
//
//  Created by Tim Storey on 24/02/2019.
//  Copyright © 2019 Tim Storey. All rights reserved.
//

#include <iostream>

/*
 * NOTE: the order is important here, GL must be before GLFW
 * we aren't using GLEW as the functions it wraps are already
 * part of the OSx implementation of OpenGL. This is not the case
 * on other platforms I believe where we need to use it to load the
 * OpenGl functions.
 */
#include <OpenGL/gl.h>

#include <GLFW/glfw3.h>

#include "WindowWrangler.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    std::cout << width << std::endl;
}


void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main(int argc, const char * argv[]) {

    // Initialize GLFW
    if(!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

#ifdef __APPLE__
    // Select OpenGL 4.1
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
    // Select OpenGL 4.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#endif

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    // get the monitor resolution etc.
    std::string title = "My Window -- ";
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    GLFWwindow* window = glfwCreateWindow(800, 600, title.c_str(), nullptr, nullptr);

    if(!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    //we have to use the context or nothing happens to the window in the event loop
    glfwMakeContextCurrent(window);

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    // Event loop this is where the magic happens
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);
        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
    return EXIT_SUCCESS;
}


