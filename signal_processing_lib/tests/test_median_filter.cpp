#include <iostream>
#include "signal_processing/median_filter.hpp"

template<typename T>
void runTest(const std::string& name)
{
    std::cout << "===== " << name << " =====" << std::endl;

    signal_processing::MedianFilter<T> filter(5);

    std::cout << filter.process(10) << std::endl;
    std::cout << filter.process(20) << std::endl;
    std::cout << filter.process(30) << std::endl;
    std::cout << filter.process(40) << std::endl;
    std::cout << filter.process(50) << std::endl;
    std::cout << filter.process(60) << std::endl;

    std::cout << std::endl;
}

int main()
{
    runTest<int>("int");
    runTest<float>("float");
    runTest<double>("double");

    return 0;
}