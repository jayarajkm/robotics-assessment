#include <iostream>

#include "signal_processing/moving_average_filter.hpp"

template<typename T>
void runTest(const std::string& name)
{
    std::cout << "===== " << name << " =====" << std::endl;

    signal_processing::MovingAverageFilter<T> filter(3);

    std::cout << filter.process(10) << std::endl;
    std::cout << filter.process(20) << std::endl;
    std::cout << filter.process(30) << std::endl;
    std::cout << filter.process(40) << std::endl;
    std::cout << filter.process(50) << std::endl;

    std::cout << std::endl;
}

int main()
{
    runTest<int>("int");
    runTest<float>("float");
    runTest<double>("double");

    return 0;
}