#pragma once
#include <cstddef>
#include <stdexcept>
#include <vector>

namespace signal_processing
{

template<typename T>
struct BufferResult
{
    bool replaced;
    T value;
};

template<typename T>
class CircularBuffer
{
public:
    explicit CircularBuffer(std::size_t capacity)
        : buffer(capacity),
          bufferCapacity(capacity),
          head(0),
          count(0)
    {
        if (capacity == 0)
        {
            throw std::invalid_argument("Buffer capacity must be greater than zero.");
        }
    }

    BufferResult<T> push(const T& value)
    {
        BufferResult<T> result{false, T{}};

        if (full())
        {
            result.replaced = true;
            result.value = buffer[head];
        }

        buffer[head] = value;

        head = (head + 1) % bufferCapacity;

        if (count < bufferCapacity)
        {
            ++count;
        }

        return result;
    }

    void reset()
    {
        head = 0;
        count = 0;
    }

    bool full() const
    {
        return count == bufferCapacity;
    }

    bool empty() const
    {
        return count == 0;
    }

    std::size_t size() const
    {
        return count;
    }

    std::size_t capacity() const
    {
        return bufferCapacity;
    }
    
    const T& operator[](std::size_t index) const
    {
        if (index >= count)
        {
            throw std::out_of_range("Index out of range.");
        }

    std::size_t oldestIndex =
        (head + bufferCapacity - count) % bufferCapacity;

    std::size_t actualIndex =
        (oldestIndex + index) % bufferCapacity;

        return buffer[actualIndex];
    }

private:
    std::vector<T> buffer;

    std::size_t bufferCapacity;
    std::size_t head;
    std::size_t count;
};

} // namespace signal_processing