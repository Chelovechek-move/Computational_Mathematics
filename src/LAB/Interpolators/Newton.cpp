//
// Created by vladimir on 27.09.22.
//

#include <vector>

namespace LAB::Interpolators
{
    double Newton(double x, std::vector<double> x_arr, std::vector<double> f_arr)
    {
        double res = 0.;
        for (int i = 0; i < x_arr.size(); i++)
        {
            double tmpRes = f_arr[0];
            for (int k = 0; k < i; ++k)
            {
                tmpRes *= (x - x_arr[k]);
            }
            res += tmpRes;

            for (int j = 0; j < x_arr.size(); j++)
            {
                f_arr[j] = (f_arr[j] - f_arr[j + 1]) / (x_arr[j] - x_arr[j + 1 + i]);
            }
        }
        return res;
    }
}