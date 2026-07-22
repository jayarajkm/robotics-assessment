# Signal Processing Library

## Overview

This project implements a reusable C++17 signal processing library for robotics sensor data. It demonstrates object-oriented design, efficient filtering algorithms, and processing of real-world sensor logs.

The library provides reusable components for reading sensor data, filtering noisy signals, and exporting processed results for analysis.

---

## Features

- CSV sensor log reader
- Generic circular buffer
- Generic filter interface
- Moving Average Filter
- Low Pass Filter
- Median Filter
- Signal processing pipeline
- Benchmarking using `std::chrono`
- Export processed results to CSV

---

## Project Structure

```
include/
    signal_processing/
        sensor_reading.hpp
        csv_reader.hpp
        circular_buffer.hpp
        filter.hpp
        moving_average_filter.hpp
        low_pass_filter.hpp
        median_filter.hpp

src/
    csv_reader.cpp

tests/
    test_csv_reader.cpp
    test_moving_average_filter.cpp
    test_low_pass_filter.cpp
    test_median_filter.cpp
    test_signal_pipeline.cpp
```

---

## Design

### SensorReading

Stores one sensor sample consisting of:

- Timestamp
- Encoder value
- Acceleration

---

### CircularBuffer

A generic fixed-size circular buffer used by the filters.

Features:

- Constant-time insertion
- Automatic overwrite of oldest samples
- Constant memory usage
- Random read access using `operator[]`

---

### Filter Interface

All filters implement a common interface:

```cpp
process(sample)
reset()
```

This allows filters to be exchanged without changing client code.

---

### Moving Average Filter

The moving average filter maintains a running sum.

Complexity:

- Time: O(1)
- Memory: O(window size)

The running sum avoids recalculating the average for every sample.

---

### Low Pass Filter

Implements a first-order exponential low-pass filter.

Characteristics:

- Smooths noisy sensor data
- Uses timestamps to calculate variable sampling intervals
- Constant-time processing

---

### Median Filter

The median filter removes spikes by selecting the middle value of the current window.

Characteristics:

- Resistant to outliers
- Useful for noisy robotics sensors
- Demonstrates extensibility of the filtering framework

Current implementation:

- Copies the current window
- Sorts the values
- Returns the median

Complexity:

- Time: O(n log n)
- Memory: O(window size)

---

## Signal Processing Pipeline

The pipeline:

1. Reads sensor data from CSV.
2. Applies Moving Average filtering.
3. Applies Low Pass filtering.
4. Exports processed results.

Generated CSV:

```
processed_signal.csv
```

Columns:

```
timestamp,
encoder,
raw_acceleration,
moving_average,
low_pass
```

---

## Performance

Benchmark performed using `std::chrono`.

Example result:

```
Samples processed : 11808
Elapsed time      : 29334 microseconds
Average/sample    : 2.48 microseconds
```

Processing time is suitable for typical robotics applications operating at hundreds of Hertz.

---

## Future Improvements

Possible extensions include:

- ROS2 integration
- Kalman Filter
- Butterworth Filter
- Multi-threaded processing
- SIMD optimization
- Real-time visualization

---

## Technologies

- C++17
- STL
- CMake
- Ubuntu 24.04

---

## Author

Assessment implementation for Robotics Software Engineer evaluation.