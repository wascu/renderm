//
// Created by wasku on 19-7-31.
//

#ifndef LEARNOPENGL_GLFRENDERCALLBACK_H
#define LEARNOPENGL_GLFRENDERCALLBACK_H

#include "std_afx.h"

#include <GLFW/glfw3.h>
#include <vector>


NAMESPACE_GL_BEGIN



typedef void (*glRenderCallback)(GLFWwindow* w);

class RenderCallbackManager{
public:
    void add(glRenderCallback pf){
        l_ps.push_back(pf);
    }

    void run(GLFWwindow* w){
        for(glRenderCallback i:l_ps){
            (*i)(w);
        }
    }
private:
    std::vector<glRenderCallback> l_ps;
};


NAMESPACE_END

#endif //LEARNOPENGL_GLFRENDERCALLBACK_H
