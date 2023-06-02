//
// Created by binue on 23. 6. 1.
//

#ifndef IMAGE_PYRAMID_ORB_SLAM_PYRAMID_BUILDER_HPP
#define IMAGE_PYRAMID_ORB_SLAM_PYRAMID_BUILDER_HPP

#include <vector>

#include "opencv2/opencv.hpp"

namespace orb_slam
{
class PyramidBuilder
{
public:
  PyramidBuilder(int32_t p_level, float scale);
  ~PyramidBuilder() = default;

  void ComputeLevelInfos();

  std::vector<cv::Mat> GenerateImagePyramid(cv::Mat image);

private:
  int32_t p_level_ = 0;
  std::vector<float> inv_scales_;
};
} // namespace orb_slam

#endif //IMAGE_PYRAMID_ORB_SLAM_PYRAMID_BUILDER_HPP
