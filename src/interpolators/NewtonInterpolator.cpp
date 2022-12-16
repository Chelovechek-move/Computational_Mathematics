#include "../types/BasicTypes.hpp"
#include <vector>

namespace ComputationalMechanics::Interpolators
{
    [[nodiscard]] static scalar InterpolateByNewton(std::vector<scalar> const &xArr,
                                       std::vector<scalar> const &fArr,
                                       scalar const x) noexcept
    {
        scalar res = fArr[0];
        const integer n = fArr.size();

        for(integer i = 1; i < n; ++i)
        {
            scalar tmpRes = 0.;
            for (integer j = 0; j <= i; ++j)
            {
                scalar delta = 1.;
                for (integer k = 0; k <= i; ++k)
                    if (k != j)
                        delta *= (xArr[j] - xArr[k]);
                tmpRes += fArr[j] / delta;
            }
            for (integer j = 0; j < i; ++j)
                tmpRes *= (x - xArr[j]);
            res += tmpRes;
        }
        return res;
    }
}