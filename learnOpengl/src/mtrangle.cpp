//
// Created by wasku on 19-8-1.
//

#include <glad/glad.h>
#include "mtrangle.h"
#include "glUtilFunction.h"



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
    glBindVertexArray(vao);
//    if(m_pindex_temp_buffer){
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//    }else
//        glDrawArrays(GL_TRIANGLES,0,3);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

}

void MTrangle::setVertexArray(const std::vector<float> &vtxArr,std::vector<int>* pIndexArr) {
    n_vertex_temp_buffer_length = copyVector(vtxArr,&m_pvertex_temp_buffer);
    n_index_temp_buffer_length = copyVector(pIndexArr,&m_pindex_temp_buffer);
}

void MTrangle::prepare() {
    if(!m_pvertex_temp_buffer){
        return;
    }
    if(b_vertexArr_with_more_attr){
        m_triShader = Shader("triangle_more_attr_texture.vs","triangle_more_attr_texture.fs");
    }

    //定义顶点数组对象 VAO
    glGenVertexArrays(1,&vao);
    //定义顶点缓冲对象
    glGenBuffers(1,&vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER, n_vertex_temp_buffer_length,m_pvertex_temp_buffer,GL_STATIC_DRAW);
    //定义索引数组对象 IBO
    if(n_index_temp_buffer_length>0){
        glGenBuffers(1,&ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,n_index_temp_buffer_length,m_pindex_temp_buffer,GL_STATIC_DRAW);

        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
    }

    if(m_textureId>0){
        // bind Texture
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_textureId);

        m_triShader.setInt("texture1",0);
    }


//    glEnableVertexAttribArray(0);
//    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    // 3. 设置顶点属性指针
    //方式1
//    if(b_vertexArr_with_more_attr){
//        // 位置属性
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//        glEnableVertexAttribArray(0);
//// 颜色属性
//        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
//        glEnableVertexAttribArray(1);
//    } else{
//        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,NULL);
//        glEnableVertexAttribArray(0);
//    }
    //方式2
    if(n_vertex_atrri_pointer_array>0){
        int n_t_attri_pointer =n_vertex_atrri_pointer_array/ sizeof(int);
        int* p_t_pointer_arr = m_pvertex_atrri_pointer_array;
        int n_t_step=0;
        for(int i=0;i<n_t_attri_pointer;++i){
            n_t_step+=*(p_t_pointer_arr+i);
        }

        int n_t_interval = 0;
        for(int i = 0;i<n_t_attri_pointer;++i){
            // 属性(位置、颜色、纹理坐标)
            glVertexAttribPointer(i, *(p_t_pointer_arr+i), GL_FLOAT, GL_FALSE, n_t_step * sizeof(float), (void*)(n_t_interval*sizeof(float)));
            glEnableVertexAttribArray(i);
            n_t_interval+=*(p_t_pointer_arr+i);
        }
    }

    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}


MTrangle::~MTrangle() {
    glDeleteVertexArrays(1,&vao);
    glDeleteBuffers(1,&vbo);
    if(n_index_temp_buffer_length>0){
        glDeleteBuffers(1,&ibo);
    }
    if(m_pvertex_temp_buffer)
        free(m_pvertex_temp_buffer);
    if(m_pindex_temp_buffer)
        free(m_pindex_temp_buffer);
    if(m_pvertex_atrri_pointer_array)
        free(m_pvertex_atrri_pointer_array);
}

void MTrangle::setVtxColor(glm::vec4 &vecColor) {
    m_triShader.setVec4("vtxColor",vecColor);
}

void MTrangle::setVertexArrayWithMoreAttr(const std::vector<float> &vtxArr,std::vector<int>* pVtxAttriPointArray , std::vector<int> *pIndexArr) {
    n_vertex_temp_buffer_length = copyVector(vtxArr,&m_pvertex_temp_buffer);
    n_vertex_atrri_pointer_array = copyVector(pVtxAttriPointArray,&m_pvertex_atrri_pointer_array);



    n_index_temp_buffer_length = copyVector(pIndexArr,&m_pindex_temp_buffer);
    b_vertexArr_with_more_attr = true;
}

void MTrangle::setTexturePic(char *filePath) {
    float tw,th;
    m_textureId = loadTexture(filePath,tw,th);
}
