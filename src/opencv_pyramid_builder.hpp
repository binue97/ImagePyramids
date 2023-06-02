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
    PyramidBuilder() = default;
    ~PyramidBuilder() = default;

    GenerateImagePyramid();

private:
};
} // namespace opencv

#endif //IMAGE_PYRAMID_OPENCV_PYRAMID_BUILDER_HPP
