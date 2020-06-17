cmake_minimum_required(VERSION 2.8)
project(learnOpengl)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

message(STATUS "Begin to find package...")
# find the required packages
find_package(GLM REQUIRED)
message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")

find_package(GLFW3 REQUIRED)
message(STATUS "GLFW3 included in ${GLFW3_INCLUDE_DIR}")

find_package(ASSIMP REQUIRED)
message(STATUS "Found ASSIMP in ${ASSIMP_INCLUDE_DIR}")

find_package(OpenGL REQUIRED)
message(STATUS "Found OpenGL in ${OPENGL_INCLUDE_DIR}")

message(STATUS "end of to find package...")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../include)

set(LIBS ${GLFW3_LIBRARY} X11 Xrandr Xinerama Xi Xxf86vm Xcursor GL dl pthread ${ASSIMP_LIBRARY})

#add_library(GLAD "src/glad.c")
#set(LIBS ${LIBS} GLAD)
##
#add_library(SRC_CPP "src/renderFunctions.cpp" )
#set(LIBS ${LIBS} SRC_CPP)


AUX_SOURCE_DIRECTORY(. DIR_SRCS)

#add_library(native-lib ${DIR_SRCS})
#set(LIBS ${LIBS} native-lib

##生成可执行文件
#add_executable(learnOpengl ${DIR_SRCS} )
##链接相关的库文件
#target_link_libraries(learnOpengl ${LIBS})

#生成可执行文件
add_executable(learnOpengl glad.c glUtilFunction.cpp main.cpp mtrangle.cpp renderFunctions.cpp stb_image.cpp )
#链接相关的库文件
target_link_libraries(learnOpengl ${LIBS})

#生成可执行文件
add_executable(ogltest glad.c glUtilFunction.cpp gltest6_1.cpp mtrangle.cpp renderFunctions.cpp stb_image.cpp)
#链接相关的库文件
target_link_libraries(ogltest ${LIBS})

#生成可执行文件
add_executable(frameBuffer_gltest glad.c glUtilFunction.cpp framebuffers.cpp mtrangle.cpp renderFunctions.cpp stb_image.cpp)
#链接相关的库文件
target_link_libraries(frameBuffer_gltest ${LIBS})

#***********************************************************************************
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

file(GLOB SHADERS
        "*.vs"
        "*.fs"
        "*.gs"
        "*.jpg"
        "*.bmp"
        "*.obj"
        "*.mtl"
        )

message(STATUS "Begin to copy files ...")
foreach(SHADER ${SHADERS})
#    message(STATUS "current file is: ${SHADER}")
    file(COPY ${SHADER} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endforeach(SHADER)

file(GLOB REStexture
        "../res"
        )

foreach(RES ${REStexture})
    file(COPY ${RES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endforeach(RES)