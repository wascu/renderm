//
// Created by wasku on 19-7-31.
//

#include "renderFunctions.h"

USING_NAMESPACE_MGGL

namespace {
    bool b_switch_flag = false;
    bool b_key_press = false;
}

void RenderFunctions::processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    else if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS){

        if(b_switch_flag){
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        }else{
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        }
        b_switch_flag = !b_switch_flag;
    }else if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS){

    }
}


void RenderFunctions::showTrangle(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}