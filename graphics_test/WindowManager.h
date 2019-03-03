//
// Created by Tim Storey on 2019-03-03.
//

#ifndef OPENGL_THE_FIRST_WINDOWMANAGER_H
#define OPENGL_THE_FIRST_WINDOWMANAGER_H

#include <memory>
#include "WindowWrangler.h"

class WindowManager {
private:
    int numberOfWindows;
    std::unique_ptr<WindowWrangler> wrangler;

public:

};


#endif //OPENGL_THE_FIRST_WINDOWMANAGER_H
