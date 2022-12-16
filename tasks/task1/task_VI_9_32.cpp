#include <iostream>
#include <vector>
#include "../../src/interpolators/NewtonInterpolator.cpp"
#include "../../src/interpolators/CubicSplineInterpolator.cpp"

using namespace ComputationalMechanics;

integer main()
{
    const double x = 2010.;
    const std::vector<scalar> f_arr = {92228496. , 106021537., 123202624., 132164569., 151325798., 179323175.,
                                       203211926., 226545805., 248709873., 281421906.};
    const std::vector<scalar> x_arr = {1910., 1920., 1930., 1940., 1950., 1960., 1970., 1980., 1990., 2000.};

    std::cout << std::fixed;
    std::cout.precision(0);

    std::cout << "Newton: " << Interpolators::InterpolateByNewton(x_arr, f_arr, x) << std::endl;
    std::cout << "Cubic spline: " << Interpolators::InterpolateByCubicSpline(x_arr, f_arr, x);
}