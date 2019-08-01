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
};
NAMESPACE_END

#endif //LEARNOPENGL_RENDERFUNCTIONS_H
