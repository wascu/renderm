cmake_minimum_required(VERSION 2.8)
#project(glTest)

set(CMAKE_CXX_STANDARD 11)

set(LIBS X11  GL)

AUX_SOURCE_DIRECTORY(. SRCS_DIR)
#生成可执行文件
add_executable(glTest ${SRCS_DIR} )
#链接相关的库文件
target_link_libraries(glTest ${LIBS})