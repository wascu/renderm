//
// Created by wasku on 19-8-1.
//

#ifndef LEARNOPENGL_MTRANGLE_H
#define LEARNOPENGL_MTRANGLE_H

#include "std_afx.h"

#include <GLFW/glfw3.h>
#include <vector>

#include "shader.h"

NAMESPACE_GL_BEGIN

class MTrangle {
public:
    MTrangle();
    void render(GLFWwindow* w);
    void setVertexArray(const std::vector<float>& vtxArr);
    void prepare();

private:
    std::vector<float> m_vertex_arr;
    Shader m_triShader;

    int m_shaderProgram;
};

NAMESPACE_END


#endif //LEARNOPENGL_MTRANGLE_H
