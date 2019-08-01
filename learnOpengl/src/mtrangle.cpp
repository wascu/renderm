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

MTrangle::MTrangle()/*:m_triShader("triangle.vs","triangle.fs")*/ {}

void MTrangle::render(GLFWwindow *w) {
//    m_triShader.use();

//    glUseProgram(shaderProgram);
    glUseProgram( m_shaderProgram);
    glDrawArrays(GL_TRIANGLES,0,3);
}

void MTrangle::setVertexArray(const std::vector<float> &vtxArr) {
    m_vertex_arr.clear();
    m_vertex_arr.assign(vtxArr.begin(),vtxArr.end());
}

void MTrangle::prepare() {
    //定义一个渲染器
//    m_triShader = Shader("triangle.vs","triangle.fs");


    // check for shader compile errors
    int success;
    char infoLog[512];
    //顶点渲染器
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    //片段渲染器
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //link shader
    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram,vertexShader);
    glAttachShader(m_shaderProgram,fragmentShader);
    glLinkProgram(m_shaderProgram);
    // check for linking errors
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    std::cout << "The shaderProgram id is: " << m_shaderProgram << std::endl;
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


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