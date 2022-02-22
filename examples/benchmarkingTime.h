#ifndef BENCHMARKINGTIMEH
#define BENCHMARKINGTIMEH
#include "benchmarkingTime.cpp"
#include <iostream> // CLI IO
#include <string>
#include <chrono> // Time related functions

class Timer
{
public:
    Timer(std::string _timer_Name)
    {
        std::cout << "Starting " << _timer_Name << "..." << std::endl;
        timer_Name = _timer_Name;
        start_Time = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        Stop();
    }

    void Stop()
    {
        end_Time = std::chrono::high_resolution_clock::now();
        double us = std::chrono::time_point_cast<std::chrono::microseconds>(end_Time).time_since_epoch().count() - std::chrono::time_point_cast<std::chrono::microseconds>(start_Time).time_since_epoch().count();
        double ms = us * 0.001;
        double s = ms * 0.001;
        std::cout << timer_Name << " timer:" << std::endl;
        std::cout << "   " << us << " us" << std::endl;
        std::cout << "   " << ms << " ms" << std::endl;
        std::cout << "   " << s << " s" << std::endl << std::endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_Time;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_Time;
    std::string timer_Name;
};
#endif