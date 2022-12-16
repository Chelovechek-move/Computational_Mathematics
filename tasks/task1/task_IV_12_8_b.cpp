#include "../../src/types/BasicTypes.hpp"
#include "iostream"
#include "cmath"

using namespace ComputationalMechanics;

integer main()
{
    // First method
    scalar x1 = 0.;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "x" << i << " = " << x1 << std::endl;
        const scalar tmp = 1. / (2. * sqrt(2)) * exp(x1 * x1 - (1. / 2.));
        x1 = tmp;
    }

    std::cout << std::endl;

    // Second method
    scalar x2 = 1.5;
    for (int i = 0; i < 7; ++i)
    {
        std::cout << "x" << i << " = " << x2 << std::endl;
        const scalar tmp = sqrt(log(2. * sqrt(2.) * exp(1. / 2.) * x2));
        x2 = tmp;
    }
}
