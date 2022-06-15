#设置CMake最小版本
cmake_minimum_required(VERSION 3.5) 
#用变量PRJ指代hello_cmake
SET(PRJ hello_cmake)
#设置工程名为上述变量指代的hello_cmake
project (${PRJ}) 
#设置当前变量SRC_DIR为当前CmakeList文件夹下的src路径
SET(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
#设置当前变量INCLUDE_DIR为当前CmakeList文件夹下的include路径
SET(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
#寻找上述变量SRC_DIR路径下所有.c文件
FILE(GLOB SRC_LIST ${SRC_DIR}/*.c)
#寻找上述变量INCLUDE_DIR路径下所有.h文件
FILE(GLOB INCLUDE_LIST ${SRC_DIR}/*.h)
#将上述所有的文件和操作用SOURCE_EXE表示
SET(SOURCE_EXE ${SRC_LIST} ${INCLUDE_LIST})
#编译时将前面定义的头文件目录包含进来
INCLUDE_DIRECTORIES(${INCLUDE_DIR})
#添加可执行文件
ADD_EXECUTABLE(${PRJ} ${SOURCE_EXE})
#将生成的可执行文件定位保存在该CmakeList文件所在目录平级的code-out文件夹中
#CMAKE_CURRENT_SOURCE_DIR：表示当前CmakeList所在的目录
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/code-out)
