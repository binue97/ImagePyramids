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
    PyramidBuilder() = default;
    ~PyramidBuilder() = default;

    GenerateImagePyramid();

private:
};
} // namespace basalt

#endif //IMAGE_PYRAMID_BASALT_PYRAMID_BUILDER_HPP
