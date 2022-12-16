#include "../../third_party/Eigen/Dense"
#include "../../src/types/BasicTypes.hpp"
#include "iostream"
#include "cmath"

using namespace ComputationalMechanics;

[[nodiscard]] static Eigen::Vector2d calcNewVec(const Eigen::Vector2d &vec) noexcept
{
    return {vec.x() * vec.x() + vec.y() * vec.y() - 1,
            vec.y() - tan(vec.x())};
}

[[nodiscard]] static Eigen::Matrix2d calcNewMatrix(const Eigen::Vector2d &vec) noexcept
{
    const scalar cos_x = cos(vec.x());
    const scalar cos_xSqr = cos_x * cos_x;
    const Eigen::Matrix2d matrix {{1., -2 * vec.y()},
                                  {1 / cos_xSqr, 2 * vec.x()}};
    const scalar coef = -1 / (2 * (vec.x() + vec.y() / cos_xSqr));
    return coef * matrix;
}

integer main()
{
    const integer N = 10;
    Eigen::Vector2d x1 = {0.5, 0.5};
    Eigen::Vector2d x2 = {-0.5, -0.5};

    for (integer i = 0; i < N; ++i)
    {
        x1 = x1 + calcNewMatrix(x1) * calcNewVec(x1);
        x2 = x2 + calcNewMatrix(x2) * calcNewVec(x2);
    }

    std::cout << x1 << std::endl << std::endl;
    std::cout << x2 << std::endl;
}