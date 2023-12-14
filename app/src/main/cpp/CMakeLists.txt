cmake_minimum_required(VERSION 3.10.2)

project("ndktest")

# 批量导入
file(GLOB appCPP *.cpp)
# native-lib：变量名 最终会生成so的名字
# SHARED：动态库 STATIC：静态库
# ${appCPP} 源文件 ，所有的cpp文件
add_library(
        native-lib
        SHARED # 动态库
        ${appCPP})


#include_directories("${CMAKE_SOURCE_DIR}/cpp/")
# CMAKE_CXX_FLAGS c++的参数 会传给编译器
# CMAKE_C_FLAGS c的参数 会传给编译器
#CMAKE_SOURCE_DIR 的值是当前这个文件的地址
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../jniLibs/armeabi-v7a")

find_library(
        log-lib
        log)

#设置目标属性方法
target_link_libraries(
        native-lib
        ${log-lib}
        #链接libaddndk.so 只需要把lib和.so去掉就可以了
        addndk
)