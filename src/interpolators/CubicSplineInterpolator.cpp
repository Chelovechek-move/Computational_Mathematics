#include "../types/BasicTypes.hpp"
#include <vector>

namespace ComputationalMechanics::Interpolators
{
    struct SplineCoeficients
    {
        scalar a = 0.;
        scalar b = 0.;
        scalar c = 0.;
        scalar d = 0.;
        scalar x = 0.;
    };

    [[nodiscard]] static std::vector<SplineCoeficients> BuildInterpolant(const std::vector<scalar> &xArr,
                                                                         const std::vector<scalar> &yArr) noexcept
    {
        const integer n = xArr.size();
        std::vector<SplineCoeficients> splines{};
        for (integer i = 0; i < n; ++i)
        {
            splines.push_back({0., 0., 0., 0., 0.});
            splines[i].x = xArr[i];
            splines[i].a = yArr[i];
        }
        splines[0].c = 0.;
        splines[n - 1].c = 0.;

        std::vector<scalar> alpha{};
        std::vector<scalar> beta{};
        for (integer i = 0; i < n - 1; ++i)
        {
            alpha.push_back(0.);
            beta.push_back(0.);
        }

        for (integer i = 1; i < n - 1; ++i)
        {
            const scalar hi = xArr[i] - xArr[i - 1];
            const scalar hi1 = xArr[i + 1] - xArr[i];
            const scalar A = hi;
            const scalar C = 2.0 * (hi + hi1);
            const scalar B = hi1;
            const scalar F = 6.0 * ((yArr[i + 1] - yArr[i]) / hi1 - (yArr[i] - yArr[i - 1]) / hi);
            const scalar z = (A * alpha[i - 1] + C);
            alpha[i] = -B / z;
            beta[i] = (F - A * beta[i - 1]) / z;
        }

        for (integer i = n - 2; i > 0; --i)
        {
            splines[i].c = alpha[i] * splines[i + 1].c + beta[i];
        }

        for (integer i = n - 1; i > 0; --i)
        {
            const scalar hi = xArr[i] - xArr[i - 1];
            splines[i].d = (splines[i].c - splines[i - 1].c) / hi;
            splines[i].b = hi * (2.0 * splines[i].c + splines[i - 1].c) / 6.0 + (yArr[i] - yArr[i - 1]) / hi;
        }

        return splines;
    }

    [[nodiscard]] static scalar InterpolateByCubicSpline(const std::vector<scalar> &xArr,
                                                         const std::vector<scalar> &yArr,
                                                         const scalar x) noexcept
    {
        const std::vector<SplineCoeficients> splines = BuildInterpolant(xArr, yArr);
        const integer n = splines.size();
        SplineCoeficients s{};

        if (x <= splines[0].x)
        {
            s = splines[0];
        } else
        {
            if (x >= splines[n - 1].x)
            {
                s = splines[n - 1];
            } else
            {
                integer i = 0;
                integer j = n - 1;
                while (i + 1 < j)
                {
                    const integer k = i + (j - i) / 2;
                    if (x <= splines[k].x)
                    {
                        j = k;
                    } else
                    {
                        i = k;
                    }
                }
                s = splines[j];
            }
        }

        const scalar dx = x - s.x;
        return s.a + s.b * dx + s.c / 2 * dx * dx + s.d / 6 * dx * dx * dx;
    }
}