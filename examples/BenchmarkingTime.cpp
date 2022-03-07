/*
1.0.0
Author: Bryce Tuppurainen Jan-2022
This script 'counts' by calculating the sum of everything between 0 and iter (i.e. arithmetic series)
It does so iteratively, recursively
It demonstrates the memory usage of the application and differences in speed
between the three versions of the same method of calculating this arithmetic sum
for your hardware
Feel free to use this same method to measure the effectiveness of your own
scripts if you're curious about why we use various datastructures
Note: The Cherno has a useful video on benchmarking here in more depth: https://www.youtube.com/watch?v=YG4jexlSAjc
*/

#include "BenchmarkingTime.h"

#include <string>
#include <memory> // Determine used bytes, note that due to phenomena called paging/framing it may not be exactly what you expect
#include <chrono> // Time related functions

Timer::Timer()
{
    std::cout << "Starting timer..." << std::endl;
    timer_Name = "";
    start_Time = std::chrono::high_resolution_clock::now();
}

Timer::Timer(std::string _timer_Name)
{
    std::cout << "Starting " << _timer_Name << "..." << std::endl;
    timer_Name = _timer_Name;
    start_Time = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
    Stop();
}

void Timer::Stop()
{
    end_Time = std::chrono::high_resolution_clock::now();
    double us = std::chrono::time_point_cast<std::chrono::microseconds>(end_Time).time_since_epoch().count() - std::chrono::time_point_cast<std::chrono::microseconds>(start_Time).time_since_epoch().count();
    double ms = us * 0.001;
    double s = ms * 0.001;
    std::cout << timer_Name << " timer:" << std::endl;
    std::cout << "   " << us << " us" << std::endl;
    std::cout << "   " << ms << " ms" << std::endl;
    std::cout << "   " << s << " s" << std::endl
              << std::endl;
}