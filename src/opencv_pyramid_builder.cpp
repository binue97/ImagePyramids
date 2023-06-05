//
// Created by binue on 23. 6. 1.
//

#include "easy/profiler.h"

#include "opencv_pyramid_builder.hpp"

namespace opencv
{
PyramidBuilder::PyramidBuilder(int32_t p_level, float scale) : p_level_(p_level)
{
  EASY_BLOCK("OpenCV Pyramid_Constructor")
  inv_scales_.resize(p_level);
  float inv_scale = 1.f / scale; 

  for (int i = 0; i < p_level; ++i)
  {
    if (i == 0) 
    {
      inv_scales_[i] = 1.f;
    }
    else
    {
      inv_scales_[i] = inv_scales_[i-1] * inv_scale;
    }
  }
}


std::vector<cv::Mat> PyramidBuilder::GenerateImagePyramid(cv::Mat image)
{
  EASY_BLOCK("OpenCV Pyramid_GeneratePyramid")
  std::vector<cv::Mat> pyramid;
  pyramid.resize(p_level_);
  pyramid[0] = image;
  for (int level = 1; level < p_level_; ++level)
  {
    // OpenCV PyrDown() function is applicable with scale 2.
    // There must be some acceleration code. It's way too fast.
    // Try to disable parallel computations in OpenCV.
    cv::pyrDown(pyramid[level-1], pyramid[level]);
  }
  return pyramid;
}
} // namespace opencv
