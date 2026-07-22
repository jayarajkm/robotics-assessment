#include "signal_processing/csv_reader.hpp"

#include <sstream>

namespace signal_processing
{

CsvReader::CsvReader(const std::string& filePath)
    : file(filePath)
{
    // Skip the header row
    if (file.is_open())
    {
        std::string header;
        std::getline(file, header);
    }
}

bool CsvReader::isOpen() const
{
    return file.is_open();
}

bool CsvReader::readNext(SensorReading& reading)
{
    std::string line;

    // Read one line from the CSV
    if (!std::getline(file, line))
    {
        return false;
    }

    std::stringstream stream(line);

    std::string timestamp;
    std::string encoder;
    std::string acceleration;

    // Split the line using commas
    std::getline(stream, timestamp, ',');
    std::getline(stream, encoder, ',');
    std::getline(stream, acceleration, ',');

    // Convert text into numbers
    reading.timestamp = std::stod(timestamp);
    reading.encoder = std::stoi(encoder);
    reading.acceleration = std::stod(acceleration);

    return true;
}

} // namespace signal_processing