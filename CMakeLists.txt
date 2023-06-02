cmake_minimum_required(VERSION 3.10)
project(ImagePyramid LANGUAGES CXX)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(easy_profiler REQUIRED)

include_directories(src)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} easy_profiler)
