//
// Created by binue on 23. 6. 1.
//

#ifndef IMAGE_PYRAMID_OPENCV_PYRAMID_BUILDER_HPP
#define IMAGE_PYRAMID_OPENCV_PYRAMID_BUILDER_HPP

#include <vector>

#include "opencv2/opencv.hpp"

namespace opencv
{
class PyramidBuilder
{
public:
  PyramidBuilder(int32_t p_level, float scale);
  ~PyramidBuilder() = default;

  std::vector<cv::Mat> GenerateImagePyramid(cv::Mat image);

private:
  int32_t p_level_ = 0;
  std::vector<float> inv_scales_;
};
} // namespace opencv

#endif //IMAGE_PYRAMID_OPENCV_PYRAMID_BUILDER_HPP
