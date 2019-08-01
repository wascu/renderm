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
    rcm.add(RenderFunctions::processInput);

    MTrangle mt;
    mt.prepare();




    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        rcm.run(window);
        mt.render(window);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    std::cout << "Hello, World!" << std::endl;
    glfwTerminate();

    return 0;
}