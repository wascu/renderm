//
// Created by wasku on 19-8-20.
//


#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>


int main(){

    int width = 200;
    int height = 200;

    glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);



    std::cout<<"proj is:\n"<<glm::to_string(proj)<<std::endl;

}