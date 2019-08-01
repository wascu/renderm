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
    ~MTrangle();

private:
    std::vector<float> m_vertex_arr;
    Shader m_triShader;
    //定义顶点缓冲对象,顶点数组对象
    unsigned int vao,vbo;

    float* m_pvertex_temp_buffer= nullptr;
    size_t n_vertex_temp_buffer_length =0;
};

NAMESPACE_END


#endif //LEARNOPENGL_MTRANGLE_H
