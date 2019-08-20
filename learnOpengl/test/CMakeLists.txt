cmake_minimum_required(VERSION 2.8)
#project(glTest)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
#
#message(STATUS "Begin to find package...")
## find the required packages
#find_package(GLM REQUIRED)
#message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")
#
#find_package(GLFW3 REQUIRED)
#message(STATUS "GLFW3 included in ${GLFW3_INCLUDE_DIR}")
#
#find_package(ASSIMP REQUIRED)
#message(STATUS "Found ASSIMP in ${ASSIMP_INCLUDE_DIR}")
#
#find_package(OpenGL REQUIRED)
#message(STATUS "Found OpenGL in ${OPENGL_INCLUDE_DIR}")
#
#message(STATUS "end of to find package...")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)



set(LIBS X11  GL)


AUX_SOURCE_DIRECTORY(. SRCS_DIR)
#生成可执行文件
add_executable(glTest ${SRCS_DIR} )
#链接相关的库文件
target_link_libraries(glTest ${LIBS})