cmake_minimum_required(VERSION 3.10.2)

project("ndktest")

# 批量导入
file(GLOB appCPP *.cpp)

add_library(
        native-lib
        SHARED # 动态库
        ${appCPP})


#include_directories("${CMAKE_SOURCE_DIR}/cpp/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../jniLibs/armeabi-v7a")

find_library(
        log-lib
        log)


target_link_libraries(
        native-lib
        ${log-lib}
        addndk
)