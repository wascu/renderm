//
// Created by wasku on 19-8-1.
//

#include <glad/glad.h>
#include "mtrangle.h"



//#include <GL/glew.h>


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

void MTrangle::setVertexArray(const std::vector<float> &vtxArr,std::vector<float>* pIndexArr) {
//    if(m_pvertex_temp_buffer)
//        free(m_pvertex_temp_buffer);
//    m_pvertex_temp_buffer = nullptr;
//    if(!vtxArr.empty()){
//        int n = vtxArr.size();
//        m_pvertex_temp_buffer = new float[n];
//        n_vertex_temp_buffer_length =n* sizeof(float);
//        memcpy(m_pvertex_temp_buffer,&vtxArr[0],n_vertex_temp_buffer_length);
//    }

//    if(m_pindex_temp_buffer)
//        free(m_pindex_temp_buffer);
//    m_pindex_temp_buffer = nullptr;
//    if(pIndexArr){
//        int n = pIndexArr->size();
//        m_pindex_temp_buffer = new float[n];
//        n_index_temp_buffer_length = n*sizeof(float);
//        memcpy(m_pindex_temp_buffer,pIndexArr,n_index_temp_buffer_length);
//    }

    n_vertex_temp_buffer_length = copyVector(vtxArr,&m_pvertex_temp_buffer);

}

void MTrangle::prepare() {
    if(!m_pvertex_temp_buffer){
        return;
    }

    //定义顶点数组对象 VAO
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
    //定义顶点缓冲对象
    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER, n_vertex_temp_buffer_length,m_pvertex_temp_buffer,GL_STATIC_DRAW);
    //定义索引数组对象 IBO
    glGenBuffers(1,&ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ibo);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER,size_t)



//    glEnableVertexAttribArray(0);
//    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    // 3. 设置顶点属性指针
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,NULL);
    glEnableVertexAttribArray(0);

    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}

MTrangle::~MTrangle() {
    glDeleteVertexArrays(1,&vao);
    glDeleteBuffers(1,&vbo);
    if(m_pvertex_temp_buffer)
        free(m_pvertex_temp_buffer);
    if(m_pindex_temp_buffer)
        free(m_pindex_temp_buffer);
}
