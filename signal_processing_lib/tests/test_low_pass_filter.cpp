#include <iostream>

#include "signal_processing/low_pass_filter.hpp"

int main()
{
    signal_processing::LowPassFilter<double> filter(2.0);

    std::cout << filter.process(10.0, 0.0) << std::endl;
    std::cout << filter.process(100.0, 0.1) << std::endl;
    std::cout << filter.process(100.0, 0.2) << std::endl;
    std::cout << filter.process(100.0, 0.3) << std::endl;
    std::cout << filter.process(100.0, 0.4) << std::endl;

    return 0;
}