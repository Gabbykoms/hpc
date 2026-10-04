#include <iostream>
#include <list>
#include <algorithm>

typedef std::list<double> :: size_type list_size;

int main(){
    std::list<double> values = {2, 7.7, 3, 9.2, 1.4};
    double x = 0;

    values.sort();
    list_size mid_index = values.size()/2;
    auto mid = values.begin();
    std::advance(mid, mid_index);

    double median = 0;

    if (values.size() % 2 == 0){
        auto mid_one = values.begin();
        std::advance(mid_one, mid_index + 1);
        median = 0.5 * (*mid + *mid_one);
    }
    else
        median = *mid;

    std::cout << "Median is : " << median <<  std::endl;


}