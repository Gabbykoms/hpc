#include <iostream>
#include <numeric>
#include <vector>


int main(){
    size_t count = 0;
    std::vector<double> vals = {1.1, 2.3, 5.4, 3.2 };

    double sum = std::accumulate(vals.begin(), vals.end(), 0.0f);

    std::cout << "Average: " << sum/vals.size() << std::endl;

    return 0;
}