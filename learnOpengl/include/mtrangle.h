//
// Created by wasku on 19-8-1.
//

#ifndef LEARNOPENGL_MTRANGLE_H
#define LEARNOPENGL_MTRANGLE_H

#include "std_afx.h"

#include <GLFW/glfw3.h>
#include <vector>
#include <string.h>  //for func memcpy

#include "shader.h"

NAMESPACE_GL_BEGIN
//some templates
    template <class T>
    int copyVector(const std::vector<T>* pvec,T** ppDst){
        if(*ppDst)
            free(*ppDst);
        *ppDst = nullptr;
        if(!pvec)
            return 0;
        int l=0;
        if(!pvec->empty()){
            int n = pvec->size();
            *ppDst = new T[n];
            int ns = sizeof(T);
            l =n* ns;
            memcpy(*ppDst,&(*pvec)[0],l);
        }
        return l;
    }

    template <class T>
    int copyVector(const std::vector<T>& vec,T** ppDst){
        return copyVector(&vec,ppDst);
    }


class MTrangle {
public:
    MTrangle();
    void render(GLFWwindow* w);
    void setVertexArray(const std::vector<float> &vtxArr,std::vector<int>* pIndexArr= nullptr) ;
    void setVertexArrayWithMoreAttr(const std::vector<float> &vtxArr,std::vector<int>* pVtxAttriPointArray = nullptr ,std::vector<int>* pIndexArr= nullptr) ;
    void setTexturePic(char* filePath);
    void prepare();
    ~MTrangle();

    void setVtxColor(glm::vec4& vecColor) ;

private:
    Shader m_triShader;
    //定义顶点缓冲对象,顶点数组对象
    unsigned int vao,vbo,ibo;

    float* m_pvertex_temp_buffer= nullptr;
    //顶点属性指针(指针默认指向一个float类型的数组)的int数组
    int* m_pvertex_atrri_pointer_array= nullptr;
    int* m_pindex_temp_buffer= nullptr;
    size_t n_vertex_temp_buffer_length =0;
    size_t n_vertex_atrri_pointer_array = 0;
    size_t n_index_temp_buffer_length =0;

    unsigned int m_textureId = 0;

    bool b_vertexArr_with_more_attr=false;
};

NAMESPACE_END


#endif //LEARNOPENGL_MTRANGLE_H
