#pragma once

#include <cmath>
#include <type_traits>

#include "signal_processing/filter.hpp"

namespace signal_processing
{

template<typename T>
class LowPassFilter
{
public:
    explicit LowPassFilter(double cutoffFrequency)
        : cutoffFrequency(cutoffFrequency),
          previousOutput(0),
          previousTimestamp(0.0),
          initialized(false)
    {
    }

    T process(const T& sample, double timestamp)
{
    if (!initialized)
    {
        previousOutput = sample;
        previousTimestamp = timestamp;
        initialized = true;

        return sample;
    }

    double dt = timestamp - previousTimestamp;

    double tau = 1.0 / (2.0 * M_PI * cutoffFrequency);

    double alpha = dt / (tau + dt);

    double filtered =
    previousOutput +
    alpha *
    (static_cast<double>(sample) - previousOutput);

    previousOutput = filtered;

    previousTimestamp = timestamp;

    return static_cast<T>(previousOutput);
}

private:
    double cutoffFrequency;

    double previousOutput;

    double previousTimestamp;

    bool initialized;
};

} // namespace signal_processing