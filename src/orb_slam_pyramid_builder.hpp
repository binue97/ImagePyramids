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
    PyramidBuilder() = default;
    ~PyramidBuilder() = default;

    GenerateImagePyramid();

private:
};
} // namespace orb_slam

#endif //IMAGE_PYRAMID_ORB_SLAM_PYRAMID_BUILDER_HPP
