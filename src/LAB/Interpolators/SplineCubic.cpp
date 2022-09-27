//
// Created by vladimir on 27.09.22.
//

#include <vector>
#include <array>

namespace LAB::Interpolators
{
    double SplineCubic(double x, std::vector<double> x_arr, std::vector<double> f_arr)
    {
        int n = x_arr.size();
        std::vector<double> a = x_arr;
        std::vector<double> b(n-1);
        std::vector<double> d(n-1);

        std::vector<double> h(n-1);
        for(int i = 0; i < n - 1; ++i)
        {
            h[i] = x_arr[i+1] - x_arr[i];
        }

        std::vector<double> alfa(n-1);
        for(int i = 1; i < n - 1; ++i)
        {
            alfa[i] = (3. / h[i]) * (a[i+1] - a[i]) - (3 / h[i-1]) * (a[i] - a[i-1]);
        }

        std::vector<double> c(n);
        std::vector<double> l(n);
        std::vector<double> m(n);
        std::vector<double> z(n);
        l[0] = 1.;
        m[0] = 0.;
        z[0] = 0.;

        for(int i = 1; i < n - 1; ++i)
        {
            l[i] = 2 * (x_arr[i+1] - x_arr[i-1]) - h[i-1] * m[i-1];
            m[i] = h[i] / l[i];
            z[i] = (alfa[i] - h[i-1] * z[i-1]) / l[i];
        }

        l[n] = 1;
        z[n] = 0;
        c[n] = 0;

        for(int i = n-1; i >= 0; --i)
        {
            c[i] = z[i] - m[i] * c[i+1];
            b[i] = (a[i+1] - a[i]) / h[i] - (h[i] * (c[i+1] + 2 * c[i])) / 3;
            d[i] = (c[i+1] - c[i]) / (3 * h[i]);
        }

        double res = 0.;
        for(int i = 0; i < n - 1; ++i)
        {
            if(x >= x_arr[i] && x < x_arr[i+1])
            {
                res = a[i] + b[i] * (x - x_arr[i]) + (c[i] / 2) * (x - x_arr[i]) * (x - x_arr[i]) + (d[i] / 6) * (x - x_arr[i]) * (x - x_arr[i]) * (x - x_arr[i]);
            }
        }
        return res;
    }
}