#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main(){

    const std::size_t n = 20;
    const double x = .372;

    std::vector<double> parts(n);
    std::iota(parts.begin(), parts.end(), 1);

    std::for_each(parts.begin(), parts.end(), [x](double &e){
        e = std::pow(-1.0, e+1) * std::pow(x,e)/(e);
    });

    double result = std::accumulate(parts.begin(), parts.end(), 0.0);
    std::cout << "ln(1 + " << x << ") ≈ " << result << std::endl;

}