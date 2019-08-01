//
// Created by wasku on 19-8-1.
//

#include <glad/glad.h>
#include "mtrangle.h"



const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                   "}\n\0";

USING_NAMESPACE_MGGL

MTrangle::MTrangle():m_triShader("triangle.vs","triangle.fs") {}

void MTrangle::render(GLFWwindow *w) {
    m_triShader.use();

    glDrawArrays(GL_TRIANGLES,0,3);
}

void MTrangle::setVertexArray(const std::vector<float> &vtxArr) {
    m_vertex_arr.clear();
    m_vertex_arr.assign(vtxArr.begin(),vtxArr.end());
}

void MTrangle::prepare() {
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    //定义顶点缓冲对象
    unsigned int vbo;
    glGenBuffers(1,&vbo);

    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW);
    //定义顶点数组对象 VAO
    unsigned int vao;
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
//    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,NULL);
    glEnableVertexAttribArray(0);
}