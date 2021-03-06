cmake_minimum_required(VERSION 3.13)

if(APPLE)
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_MACOSX_RPATH 1)
    add_compile_definitions(GL_SILENCE_DEPRECATION)
else()
    find_package(GLEW REQUIRED)
    include_directories(${GLEW_INCLUDE_DIRS})
endif()

#set(CMAKE_VERBOSE_MAKEFILE on)

project(OpenGl_the_first)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

add_executable(testWindow main.cpp WindowWrangler.cpp WindowWrangler.h WindowManager.cpp WindowManager.h)

add_library(LIB_GLFW SHARED IMPORTED GLOBAL)

set_target_properties(LIB_GLFW PROPERTIES
        LINKER_LANGUAGE CXX
        IMPORTED_LOCATION /usr/local/lib/libglfw.3.3.dylib
        INTERFACE_INCLUDE_DIRECTORIES /usr/local/include
        )

target_link_libraries(testWindow LIB_GLFW)

target_link_libraries(testWindow ${OPENGL_LIBRARIES})

if(!APPLE)
    target_link_libraries(testWindow ${GLEW_LIBRARIES})
endif()



