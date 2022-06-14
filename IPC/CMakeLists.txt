cmake_minimum_required(VERSION 3.5) #设置CMake最小版本
project (hello_cmake) #设置工程名
set(
    SOURCES
    src/hello.c
    src/main.c
)
# 将输出重定向到code-out文件夹
set(EXECUTABLE_OUTPUT_PATH ${SOURCES}/../../../../code-out)
# set(EXECUTABLE_OUTPUT_PATH /home/code/linux/code-out/CMake_out)
add_executable(hello_cmake ${SOURCES}) #生成可执行文件

target_include_directories(
    hello_cmake
    PRIVATE
        ${PROJECT_INCLUDE_DIR}/include
)
