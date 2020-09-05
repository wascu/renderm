#include <iostream>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

int main(){

    glm::mat4 projection = glm::perspective(glm::radians(60.0f), (float)800 / (float)800, 0.1f, 100.0f);

    std::cout<<"the projection is:\n"<<glm::to_string(projection)<<std::endl;

    std::cout<<"hello gltest.\n";
}