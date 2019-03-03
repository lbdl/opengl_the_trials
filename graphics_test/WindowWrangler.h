//
// Created by Tim Storey on 2019-02-25.
//

#ifndef OPENGL_THE_FIRST_WINDOWWRANGLER_H
#define OPENGL_THE_FIRST_WINDOWWRANGLER_H


#include <GLFW/glfw3.h>

class WindowWrangler {
public:
    WindowWrangler(int wd, int ht);
    ~WindowWrangler();
    void openWindow();
    void runWindowLoop();

private:
    class impl;
    std::unique_ptr<impl> pimpl;
};


#endif //OPENGL_THE_FIRST_WINDOWWRANGLER_H
