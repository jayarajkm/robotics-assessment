#pragma once

namespace signal_processing
{

template<typename T>
class Filter
{
public:
    virtual ~Filter() = default;

    virtual T process(const T& sample) = 0;

    virtual void reset() = 0;
};

} // namespace signal_processing