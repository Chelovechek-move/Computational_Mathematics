//
// Created by vladimir on 27.09.22.
//

#include <iostream>
#include <vector>
#include "../src/LAB/Interpolators/SplineCubic.cpp"

int main(){
    const double x = 0.95;
    const std::vector<double> f_arr = {0., 0.033, 0.067, 0.100, 0.134, 0.168, 0.203, 0.238, 0.273, 0.309, 0.346};
    const std::vector<double> x_arr = {0., 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.};
    std::cout << LAB::Interpolators::SplineCubic(x, x_arr, f_arr);
}