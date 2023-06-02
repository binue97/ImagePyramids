cmake_minimum_required(VERSION 3.10)
project(ImagePyramid LANGUAGES CXX)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(easy_profiler REQUIRED)

include_directories(src)

set(SRC_FILES
      src/orb_slam_pyramid_builder.cpp
      )

add_executable(${PROJECT_NAME} 
  main.cpp
  ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} 
  easy_profiler
  ${OpenCV_LIBS})
