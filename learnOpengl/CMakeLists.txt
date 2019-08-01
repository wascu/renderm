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

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)


set(LIBS ${GLFW3_LIBRARY} X11 Xrandr Xinerama Xi Xxf86vm Xcursor GL dl pthread ${ASSIMP_LIBRARY})

#add_library(GLAD "src/glad.c")
#set(LIBS ${LIBS} GLAD)
##
#add_library(SRC_CPP "src/renderFunctions.cpp" )
#set(LIBS ${LIBS} SRC_CPP)


AUX_SOURCE_DIRECTORY(src DIR_SRCS)

add_library(native-lib ${DIR_SRCS})
set(LIBS ${LIBS} native-lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(learnOpengl ${DIR_SRCS} )
target_link_libraries(learnOpengl ${LIBS})

add_subdirectory(src)


#OPTION(USE_DEBUG
#        "Build the project using debug"
#        OFF)
#
#IF(USE_DEBUG)
#    add_definitions("-DDEBUG")
#endif(USE_DEBUG)
#
#add_definitions("-Wall -g")
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
#
## find the required packages
#find_package(GLM REQUIRED)
#message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")
#
##find_package( OpenCV REQUIRED )
##message(STATUS "OpenCV included at ${OpenCV_INCLUDE_DIR}")
#
#find_package(GLFW3 REQUIRED)
#message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")
#
#find_package(ASSIMP REQUIRED)
#message(STATUS "Found ASSIMP in ${ASSIMP_INCLUDE_DIR}")
#
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
#find_package(OpenGL REQUIRED)
#add_definitions(${OPENGL_DEFINITIONS})
#find_package(X11 REQUIRED)
#
## note that the order is important for setting the libs
## use pkg-config --libs $(pkg-config --print-requires --print-requires-private glfw3) in a terminal to confirm
##set(LIBS ${GLFW3_LIBRARY} X11 Xrandr Xinerama Xi Xxf86vm Xcursor GL dl pthread ${ASSIMP_LIBRARY} ${OpenCV_LIBS})
#set(LIBS ${GLFW3_LIBRARY} X11 Xrandr Xinerama Xi Xxf86vm Xcursor GL dl pthread ${ASSIMP_LIBRARY})
#set (CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")
#
##add_library(STB_IMAGE "src/main.cpp")
##set(LIBS ${LIBS} STB_IMAGE)
#
#
#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
#include_directories(${PROJECT_SOURCE_DIR}/include)
##include_directories( ${OpenCV_INCLUDE_DIRS} )
##add_subdirectory(src)
#AUX_SOURCE_DIRECTORY(src DIR_SRCS)
#
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#
#file(GLOB SHADERS
#        "*.vs"
#        "*.fs"
#        "*.gs"
#        "*.jpg"
#        "*.bmp"
#        "*.obj"
#        "*.mtl"
#        )
#
#foreach(SHADER ${SHADERS})
#    file(COPY ${SHADER} DESTINATION ${PROJECT_SOURCE_DIR}/bin)
#endforeach(SHADER)
#
#add_executable(learnOpengl ${DIR_SRCS})
#target_link_libraries(learnOpengl ${LIBS})
