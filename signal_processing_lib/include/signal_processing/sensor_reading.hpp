#pragma once

namespace signal_processing
{

struct SensorReading
{
    double timestamp;
    int encoder;
    double acceleration;
};

} // namespace signal_processing