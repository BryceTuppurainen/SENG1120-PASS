#ifndef BENCHMARKINGTIMEH
#define BENCHMARKINGTIMEH

#include <iostream> // CLI IO
#include <string>
#include <chrono> // Time related functions

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_Time;

    std::chrono::time_point<std::chrono::high_resolution_clock> end_Time;

    std::string timer_Name;

public:
    Timer();

    Timer(std::string _timer_Name);

    ~Timer();

    void Stop();
};

#endif