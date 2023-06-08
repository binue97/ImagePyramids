//
// Created by binue on 23. 6. 1.
//

#include "easy/profiler.h"

#include "basalt_pyramid_builder.hpp"

namespace basalt
{
PyramidBuilder::PyramidBuilder(int32_t levels, float scale) : pyr_level_(levels)
{
  EASY_BLOCK("Basalt::Pyramid_Constructor", profiler::colors::Teal)
  inv_scales_.resize(pyr_level_);
  float inv_scale = 1.f / scale; 

  for (int i = 0; i < pyr_level_; ++i)
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


cv::Mat PyramidBuilder::GenerateImagePyramid(cv::Mat image)
{
  EASY_BLOCK("Basalt::Pyramid_GeneratePyramid", profiler::colors::Teal)
  
  constexpr int32_t kernel[5] = {0, 0, 16, 0, 0};
  orig_rows_ = image.rows;
  orig_cols_ = image.cols;
  pyramid_image_ = cv::Mat(image.rows, image.cols * 1.5, image.type());
  image.copyTo(pyramid_image_(cv::Rect(0, 0, image.cols, pyramid_image_.rows)));
  
  for (int level = 1; level < pyr_level_; ++level)
  {
    cv::Rect prev_area = GetArea(level-1);
    cv::Rect cur_area = GetArea(level);
    cv::Mat prev_img = pyramid_image_(prev_area);
    cv::Mat cur_img = pyramid_image_(cur_area);
    cv::Mat tmp(prev_img.cols, cur_img.rows, CV_32SC1);
    
    // Vertical convolution
    for (int32_t r = 0; r < cur_img.rows; ++r)
    {
      const uint8_t* row_m2 = prev_img.ptr<uint8_t>(std::abs(2 * r - 2));
      const uint8_t* row_m1 = prev_img.ptr<uint8_t>(std::abs(2 * r - 1));
      const uint8_t* row = prev_img.ptr<uint8_t>(2 * r);
      const uint8_t* row_p1 = prev_img.ptr<uint8_t>(Border101(2 * r + 1, prev_img.rows));
      const uint8_t* row_p2 = prev_img.ptr<uint8_t>(Border101(2 * r + 2, prev_img.rows));

      for (int c = 0; c < prev_img.cols; ++c)
      {
        tmp.at<int32_t>(c, r) = kernel[0] * row_m2[c] + kernel[1] * row_m1[c] + 
                                kernel[2] * row[c] + kernel[3] * row_p1[c] +
                                kernel[4] * row_p2[c];
      }
    }

    // Horizontal convolution
    for (int32_t c = 0; c < cur_img.cols; ++c) 
    {
      const int32_t* row_m2 = tmp.ptr<int32_t>(std::abs(2 * c - 2));
      const int32_t* row_m1 = tmp.ptr<int32_t>(std::abs(2 * c - 1));
      const int32_t* row = tmp.ptr<int32_t>(2 * c);
      const int32_t* row_p1 = tmp.ptr<int32_t>(Border101(2 * c + 1, tmp.rows));
      const int32_t* row_p2 = tmp.ptr<int32_t>(Border101(2 * c + 2, tmp.rows));

      // Convention !
      for (int32_t r = 0; r < tmp.cols; ++r) 
      {
        int32_t val_int32 = kernel[0] * row_m2[r] + kernel[1] * row_m1[r] +
                            kernel[2] * row[r] + kernel[3] * row_p1[r] +
                            kernel[4] * row_p2[r];
        uint8_t val = ((val_int32 + (1 << 7)) >> 8);
        cur_img.at<uint8_t>(r, c) = val;
      }
    }
  }
  // cv::imshow("Pyramid_image", pyramid_image_);
  // cv::waitKey(0);

  return pyramid_image_;
}
} // namespace basalt
