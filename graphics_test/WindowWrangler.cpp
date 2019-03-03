//
// Created by Tim Storey on 2019-02-25.
//

#include <iostream>
#include "WindowWrangler.h"

class WindowWrangler::impl {
public:

    impl(int w, int h) {
        wHeight = h;
        wWidth = w;
    }

    int wHeight;
    int wWidth;

    GLFWwindow *window;

    static void size_callback(GLFWwindow *window, int width, int height) {
        glViewport(0, 0, width, height);
        std::cout << width << std::endl;
    }

    void processInput(GLFWwindow *window) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    void setHandlers() {
        glfwSetWindowSizeCallback(this->window, this->size_callback);
    }

    void setupGLFWindow() {
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
        GLFWmonitor *monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode *mode = glfwGetVideoMode(monitor);
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    }

private:

};


WindowWrangler::WindowWrangler(int wd, int ht) : pimpl(new impl(wd, ht)) {
    // Initialize GLFW
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
}

void WindowWrangler::openWindow() {

    std::string title = "My Window";

    pimpl->setupGLFWindow();

    pimpl->window = glfwCreateWindow(800, 600, title.c_str(), nullptr, nullptr);

    pimpl->setHandlers();



    if (!pimpl->window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    //we have to use the context or nothing happens to the window in the event loop
    glfwMakeContextCurrent(pimpl->window);

    glViewport(0, 0, 800, 600);
}

void WindowWrangler::runWindowLoop() {
    while (!glfwWindowShouldClose(pimpl->window)) {
        pimpl->processInput(pimpl->window);
        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(pimpl->window);
        glfwPollEvents();
    }
}

