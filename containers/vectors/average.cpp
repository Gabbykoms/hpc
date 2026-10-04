#include <iostream>
#include <vector>


int main(){
    double sum = 0;
    size_t count = 0;
    std::vector<double> vals = {1, 3, 7, 2.2, 1.8};

    std:: cout << "This program runs" << std::endl;
    for (auto x : vals){
        sum += x;
        ++count;
    }

    std::cout << "Average: " << sum/count << std::endl;

    return 0;
}