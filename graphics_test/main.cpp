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
#include "WindowManager.h"

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


    auto windowMgr = std::make_unique<WindowWrangler>(WindowWrangler(800, 800));

    windowMgr->openWindow();

    windowMgr->runWindowLoop();


    // Terminate GLFW
    // we hit this when the windowManager returns back to main
    glfwTerminate();

    return EXIT_SUCCESS;
}


