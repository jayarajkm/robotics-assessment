#pragma once

#include <fstream>
#include <string>

#include "signal_processing/sensor_reading.hpp"

namespace signal_processing
{

class CsvReader
{
public:
    // Opens the CSV file
    explicit CsvReader(const std::string& filePath);

    // Returns true if the file opened successfully
    bool isOpen() const;

    // Reads the next row from the CSV
    // Returns false when there are no more rows
    bool readNext(SensorReading& reading);

private:
    std::ifstream file;
};

} // namespace signal_processing