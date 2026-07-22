#include <iostream>
#include <chrono>
#include "signal_processing/csv_reader.hpp"
#include "signal_processing/moving_average_filter.hpp"
#include "signal_processing/low_pass_filter.hpp"
#include <fstream>
#include <iostream>

#include "signal_processing/csv_reader.hpp"
#include "signal_processing/moving_average_filter.hpp"
#include "signal_processing/low_pass_filter.hpp"

int main()
{
    signal_processing::CsvReader reader("../sensor_log.csv");

    signal_processing::MovingAverageFilter<double> movingAverage(10);

    signal_processing::LowPassFilter<double> lowPass(5.0);

    std::ofstream output("processed_signal.csv");

    if (!output)
    {
        std::cerr << "Failed to create output file." << std::endl;
        return 1;
    }

    output << "timestamp,"
           << "encoder,"
           << "raw_acceleration,"
           << "moving_average,"
           << "low_pass\n";

    signal_processing::SensorReading reading;

    auto start = std::chrono::high_resolution_clock::now();
    std::size_t sampleCount = 0;

    while (reader.readNext(reading))
    {
        double movingAverageValue =
            movingAverage.process(reading.acceleration);

        double lowPassValue =
            lowPass.process(
                reading.acceleration,
                reading.timestamp);

        output
            << reading.timestamp << ','
            << reading.encoder << ','
            << reading.acceleration << ','
            << movingAverageValue << ','
            << lowPassValue << '\n';

            ++sampleCount;
    }

    output.close();

    std::cout
        << "Processed data written to processed_signal.csv"
        << std::endl;
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(
            end - start);

    std::cout << "Samples processed : "
            << sampleCount << '\n';

    std::cout << "Elapsed time      : "
            << elapsed.count()
            << " microseconds\n";

    std::cout << "Average/sample    : "
            << static_cast<double>(elapsed.count()) / sampleCount
            << " microseconds\n";

    return 0;
}