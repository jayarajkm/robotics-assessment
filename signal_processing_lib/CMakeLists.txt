cmake_minimum_required(VERSION 3.16)

project(signal_processing_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

#
# Library
#
add_library(signal_processing
    src/csv_reader.cpp
)

#
# Tests
#
add_executable(test_csv_reader
    tests/test_csv_reader.cpp
)

target_link_libraries(test_csv_reader
    signal_processing
)

add_executable(test_moving_average_filter
    tests/test_moving_average_filter.cpp
)

target_link_libraries(test_moving_average_filter
    signal_processing
)

add_executable(test_low_pass_filter
    tests/test_low_pass_filter.cpp
)

target_link_libraries(test_low_pass_filter
    signal_processing
)

add_executable(test_signal_pipeline
    tests/test_signal_pipeline.cpp
)

target_link_libraries(test_signal_pipeline
    signal_processing
)

#
# Median Filter Test
#
add_executable(test_median_filter
    tests/test_median_filter.cpp
)

target_link_libraries(test_median_filter
    signal_processing
)