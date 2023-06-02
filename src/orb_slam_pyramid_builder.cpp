//
// Created by binue on 23. 6. 1.
//

#include "orb_slam_pyramid_builder.hpp"

namespace orb_slam
{
PyramidBuilder::PyramidBuilder(int32_t p_level, float scale) : p_level_(p_level)
{
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
  constexpr int32_t EDGE_THRESHOLD = 19;
  std::vector<cv::Mat> pyramid;
  pyramid.resize(p_level_);

  for (int level = 0; level < p_level_; ++level)
  {
    float inv_scale = inv_scales_[level];
    cv::Size sz(cvRound((float)image.cols * inv_scale), cvRound((float)image.rows * inv_scale));
    cv::Size wholeSize(sz.width + EDGE_THRESHOLD*2, sz.height + EDGE_THRESHOLD*2);
    cv::Mat temp(wholeSize, image.type());
    auto r = cv::Rect(EDGE_THRESHOLD, EDGE_THRESHOLD, sz.width, sz.height);
    pyramid[level] = temp(cv::Rect(EDGE_THRESHOLD, EDGE_THRESHOLD, sz.width, sz.height));
    if( level != 0 )
    {
      resize(pyramid[level-1], pyramid[level], sz, 0, 0, cv::INTER_LINEAR);

      copyMakeBorder(pyramid[level], temp, EDGE_THRESHOLD, EDGE_THRESHOLD, EDGE_THRESHOLD, EDGE_THRESHOLD,
                      cv::BORDER_REFLECT_101+cv::BORDER_ISOLATED);
    }
    else
    {
      copyMakeBorder(image, temp, EDGE_THRESHOLD, EDGE_THRESHOLD, EDGE_THRESHOLD, EDGE_THRESHOLD,
                      cv::BORDER_REFLECT_101);
    }
    cv::imshow(std::to_string(level), pyramid[level]);
  }
  cv::waitKey(0);

  // TODO (Apply Gaussian Blur)
  





  return pyramid;
}
} // namespace orb_slam
