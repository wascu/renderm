//
// Created by wasku on 19-7-31.
//

#include "renderFunctions.h"

USING_NAMESPACE_MGGL

namespace {
    bool b_switch_flag = false;
    //这里可以采用glut来监听键盘
    bool b_key_press = false;
}

//这里可以采用glut来监听键盘
void RenderFunctions::processInput(GLFWwindow *window){
}


void RenderFunctions::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_E && action == GLFW_PRESS){
        if(b_switch_flag){
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        }else{
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        }
        b_switch_flag = !b_switch_flag;
    }else if(key == GLFW_KEY_Q && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}


void RenderFunctions::showTrangle(GLFWwindow *window){
}

void RenderFunctions::mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        //sth to do
    }
}

void RenderFunctions::cursor_position_callback(GLFWwindow *window, double xpos, double ypos) {
    //sth to do
}
