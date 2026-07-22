#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "signal_processing/circular_buffer.hpp"
#include "signal_processing/filter.hpp"

namespace signal_processing
{

template<typename T>
class MovingAverageFilter : public Filter<T>
{
public:
    explicit MovingAverageFilter(std::size_t windowSize)
        : buffer(windowSize),
          accumulator(0)
    {
    }

    T process(const T& sample) override
    {
        auto result = buffer.push(sample);

        if (result.replaced)
        {
            accumulator -= static_cast<AccumulatorType>(result.value);
        }

        accumulator += static_cast<AccumulatorType>(sample);

        return static_cast<T>(accumulator / buffer.size());
    }

    void reset() override
    {
        buffer.reset();
        accumulator = 0;
    }

private:

    using AccumulatorType =
        std::conditional_t<
            std::is_integral_v<T>,
            std::int64_t,
            double>;

    CircularBuffer<T> buffer;

    AccumulatorType accumulator;
};

} // namespace signal_processing