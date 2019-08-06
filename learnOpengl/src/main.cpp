#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "glwSetting.h"
#include "glfRenderCallBack.h"
#include "renderFunctions.h"
#include "mtrangle.h"

//using namespace glm;

USING_NAMESPACE_MGGL

int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(ns_MG_GL::WINDOW_WIDTH, ns_MG_GL::WINDOW_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    RenderCallbackManager rcm;
//    rcm.add(RenderFunctions::processInput);


    std::vector<float> vec_vertexs ({-0.5f, -0.5f, 0.0f,
                                     0.5f, -0.5f, 0.0f,
                                     0.0f,  0.5f, 0.0f});

    std::vector<float> vertices ({0.5f, 0.5f, 0.0f,   // 右上角
                                  0.5f, -0.5f, 0.0f,  // 右下角
                                  -0.5f, -0.5f, 0.0f, // 左下角
                                  -0.5f, 0.5f, 0.0f   // 左上角
                                   });

    std::vector<int> indices ({       // 注意索引从0开始!
                                      0, 1, 3, // 第一个三角形
                                      1, 2, 3  // 第二个三角形
                                 });


    MTrangle mt;
//    mt.setVertexArray(vec_vertexs);
    mt.setVertexArray(vertices,&indices);
    mt.prepare();
    glm::vec4 vcolor(0.9f, 0.1f, 0.2f, 1.0f);

//    glfwSetInputMode(window,GLFW_STICKY_KEYS,GL_FALSE);
    glfwSetKeyCallback(window,RenderFunctions::key_callback);
    //鼠标指针移动事件
//    glfwSetCursorPosCallback(window, cursor_pos_callback);
//    鼠标点击事件
//    glfwSetMouseButtonCallback(window, mouse_button_callback);

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        rcm.run(window);
        mt.render(window);
        mt.setVtxColor(vcolor);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    std::cout << "Hello, World!" << std::endl;
    glfwTerminate();

    return 0;
}