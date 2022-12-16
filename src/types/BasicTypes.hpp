#ifndef PROJECT_BALLISTICS_BASICTYPES_HPP
#define PROJECT_BALLISTICS_BASICTYPES_HPP

#include <cstdint>
#include "../third_party/Eigen/Dense"

namespace ComputationalMechanics
{
    using scalar = double;
    using integer = std::int32_t;
    using vector3d = Eigen::Vector3d;
    using quaterniond = Eigen::Quaterniond;
}

#endif //PROJECT_BALLISTICS_BASICTYPES_HPP
