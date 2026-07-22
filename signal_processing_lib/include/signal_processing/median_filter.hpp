#pragma once

#include <algorithm>
#include <vector>

#include "filter.hpp"
#include "circular_buffer.hpp"

namespace signal_processing
{

template<typename T>
class MedianFilter : public Filter<T>
{
public:
    explicit MedianFilter(std::size_t windowSize)
        : buffer(windowSize),
          values(windowSize)
    {
    }

    T process(const T& sample) override
    {
        buffer.push(sample);

        // Copy the active elements from the circular buffer
        for (std::size_t i = 0; i < buffer.size(); ++i)
        {
            values[i] = buffer[i];
        }

        // Sort only the active portion of the buffer
        std::sort(values.begin(), values.begin() + buffer.size());

        // Return the median element
        return values[buffer.size() / 2];
    }

    void reset() override
    {
        buffer.reset();
    }

private:
    CircularBuffer<T> buffer;
    std::vector<T> values;
};

} // namespace signal_processing