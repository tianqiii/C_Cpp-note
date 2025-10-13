cmake_minimum_required(VERSION 3.30)

project(HelloWorld)

include_directories("Header Files") # 包含头文件目录
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

#开启所有警告和错误
add_compile_options(-Wall) #-Werror) 

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED OFF) # 不严格遵循c++标准
set(CMAKE_CXX_EXTENSIONS OFF) # 不允许使用编译器的特殊扩展

set(source_dir "${PROJECT_SOURCE_DIR}/src/")
# file(GLOB source_files "${source_dir}/*.cpp")
set(SOURCES
    ${source_dir}/Main.cpp
    ${source_dir}/Log.cpp
)
# 设置可执行文件和库文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")  # 静态库

# file(GLOB source_files "${source_dir}/*.cpp")
#定义输出的是可执行文件还是库
add_executable(HelloWorld ${SOURCES})