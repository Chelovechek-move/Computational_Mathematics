#include "../../src/types/BasicTypes.hpp"
#include "iostream"
#include "cmath"
#include "array"

using namespace ComputationalMechanics;

integer main()
{
    const integer N = 10000000;
    const scalar xMin = 0.;
    const scalar xMax = 3.;
    const scalar delta = xMax - xMin;
    const scalar step = delta / N;

    std::vector<scalar> x(N + 1);
    for (integer i = 0; i <= N; ++i)
    {
        x[i] = step * i;
    }

    std::vector<scalar> y(N + 1);
    for (integer i = 0; i <= N; ++i)
    {
        const scalar xSqr = x[i] * x[i];
        y[i] = sin(100 * x[i]) * exp(-xSqr) * (1 - 2 * xSqr + (2 / 3) * xSqr * xSqr);
    }

    scalar ans = 0.;
    for (integer i = 0; i < N; ++i)
    {
        const scalar I = 0.5 * (y[i] + y[i + 1]) * step;
        ans += I;
    }

    std::cout << ans << std::endl;
}

