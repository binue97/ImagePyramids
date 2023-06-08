cmake_minimum_required(VERSION 3.10)
project(ImagePyramid LANGUAGES CXX)


if (CMAKE_BUILD_TYPE MATCHES "Release")
  find_package(OpenCV 4.4.0 EXACT REQUIRED PATHS ${CMAKE_SOURCE_DIR}/thirdparty/opencv/install/Release/lib/cmake/opencv4 NO_DEFAULT_PATH)
  message(STATUS "Found OpenCV library: " ${OpenCV_INCLUDE_DIRS})
endif ()
if (CMAKE_BUILD_TYPE MATCHES "Debug")
  find_package(OpenCV 4.4.0 EXACT REQUIRED PATHS ${CMAKE_SOURCE_DIR}/thirdparty/opencv/install/Debug/lib/cmake/opencv4 NO_DEFAULT_PATH)
  message(STATUS "Found OpenCV library: " ${OpenCV_INCLUDE_DIRS})
endif ()

find_package(Eigen3 REQUIRED)
find_package(easy_profiler REQUIRED)

include_directories(src)

set(SRC_FILES
      src/orb_slam_pyramid_builder.cpp
      src/opencv_pyramid_builder.cpp
      src/basalt_pyramid_builder.cpp
      )

add_executable(${PROJECT_NAME} 
  main.cpp
  ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} 
  easy_profiler
  ${OpenCV_LIBS})
