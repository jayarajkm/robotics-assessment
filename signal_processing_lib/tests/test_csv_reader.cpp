#include <iostream>

#include "signal_processing/csv_reader.hpp"

int main()
{
    signal_processing::CsvReader reader("../sensor_log.csv");

    if (!reader.isOpen())
    {
        std::cout << "Failed to open file!" << std::endl;
        return 1;
    }

    std::cout << "File opened successfully!" << std::endl;

    signal_processing::SensorReading reading;

    while (reader.readNext(reading))
    {
        std::cout
            << reading.timestamp << " "
            << reading.encoder << " "
            << reading.acceleration
            << std::endl;
    }

    return 0;
}