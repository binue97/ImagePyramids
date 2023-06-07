//
// Created by binue on 23. 6. 1.
//

#ifndef IMAGE_PYRAMID_BASALT_PYRAMID_BUILDER_HPP
#define IMAGE_PYRAMID_BASALT_PYRAMID_BUILDER_HPP

#include <vector>

#include "opencv2/opencv.hpp"

namespace basalt
{
class PyramidBuilder
{
public:
  PyramidBuilder(int32_t p_level, float scale);
  ~PyramidBuilder() = default;

  cv::Mat GenerateImagePyramid(cv::Mat image);

private:
  static inline int32_t Border101(int32_t x, int32_t h) {
    return h - 1 - std::abs(h - 1 - x);
  }

  inline cv::Rect GetArea(int32_t level)
  {
    int32_t x = (level == 0) ? 0 : orig_cols_;
    int32_t y = (level <= 1) ? 0 : pyramid_image_.rows - (pyramid_image_.rows >> (level - 1));
    int32_t w = orig_cols_ >> level;
    int32_t h = pyramid_image_.rows >> level;

    return cv::Rect(x, y, w, h);
  }

  int32_t pyr_level_ = 0;
  std::vector<float> inv_scales_;
  cv::Mat pyramid_image_;
  int32_t orig_rows_ = 0;
  int32_t orig_cols_ = 0;

};
} // namespace basalt

#endif //IMAGE_PYRAMID_BASALT_PYRAMID_BUILDER_HPP
