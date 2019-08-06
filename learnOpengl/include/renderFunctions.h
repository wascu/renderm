//
// Created by wasku on 19-7-31.
//

#ifndef LEARNOPENGL_RENDERFUNCTIONS_H
#define LEARNOPENGL_RENDERFUNCTIONS_H

#include "std_afx.h"

#include <GLFW/glfw3.h>
NAMESPACE_GL_BEGIN
class RenderFunctions {
public:
    static void processInput(GLFWwindow *window);

    static void showTrangle(GLFWwindow* w);

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};
NAMESPACE_END

#endif //LEARNOPENGL_RENDERFUNCTIONS_H
