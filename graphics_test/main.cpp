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




int main(int argc, const char * argv[]) {


    auto windowMgr = std::make_unique<WindowWrangler>(WindowWrangler(800, 800));

    windowMgr->openWindow();

    windowMgr->setTitle("Mein Schluss");

    windowMgr->runWindowLoop();


    // Terminate GLFW
    // we hit this when the windowManager returns back to main
    glfwTerminate();

    return EXIT_SUCCESS;
}


