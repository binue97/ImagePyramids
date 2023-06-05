#include <iostream>
#include <filesystem>
#include <string>

#include "easy/profiler.h"
#include "opencv2/opencv.hpp"

#include "orb_slam_pyramid_builder.hpp"
#include "opencv_pyramid_builder.hpp"

cv::Mat LoadImage(const std::string& path)
{
  return cv::imread(path, cv::IMREAD_COLOR);
}


int main(int argc, char** argv)
{
  EASY_PROFILER_ENABLE

  constexpr int32_t TEST_ITER = 100;
  constexpr int32_t PYRAMID_LEVELS = 6;
  constexpr float SCALE_FACTOR = 1.2f;

  cv::Mat image;
  if(argc == 2)
  {
    std::string path = argv[1];
    image = LoadImage(path);
  }
  else
  {
    std::cerr << "Wrong Usage!" << std::endl;
    std::cerr << "Usage: '/executable image_path.png'" << std::endl;
    exit(-1);
  }

  for (int i = 0; i < TEST_ITER ; ++i)
  {
    // ORB_SLAM Image Pyramid
    auto orb_pyramid_builder = orb_slam::PyramidBuilder(PYRAMID_LEVELS, SCALE_FACTOR);
    auto orb_pyramid = orb_pyramid_builder.GenerateImagePyramid(image);

    // OpenCV Image Pyramid
    // auto opencv_pyramid_builder = opencv::PyramidBuilder(PYRAMID_LEVELS, SCALE_FACTOR);
    // auto opencv_pyramid = opencv_pyramid_builder.GenerateImagePyramid(image);

  }
  

  profiler::dumpBlocksToFile("/home/binue/projects/experiments/ImagePyramids/result.prof");
}
