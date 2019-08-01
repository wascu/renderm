//
// Created by wasku on 19-7-31.
//

#include "renderFunctions.h"

USING_NAMESPACE_MGGL

void RenderFunctions::processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


void RenderFunctions::showTrangle(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}