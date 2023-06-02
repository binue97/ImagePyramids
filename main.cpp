#include <iostream>
#include <filesystem>
#include <string>

#include "opencv2/opencv.hpp"

#include "orb_slam_pyramid_builder.hpp"

cv::Mat LoadImage(const std::string& path)
{
  return cv::imread(path, cv::IMREAD_COLOR);
}


int main(int argc, char** argv)
{
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

  // ORB_SLAM Image Pyramid
  auto orb_pyramid = orb_slam::PyramidBuilder(PYRAMID_LEVELS, SCALE_FACTOR);
  auto v = orb_pyramid.GenerateImagePyramid(image);
}
