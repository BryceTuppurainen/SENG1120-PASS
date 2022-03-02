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

#include <iostream> // CLI IO
#include <string>

#include <memory> // Determine used bytes, note that due to phenomena called paging/framing it may not be exactly what you expect
#include <chrono> // Time related functions

#define iter 50000 // Try modding this to different +ve integer values to see how the difference changes

class Timer
{
public:
    Timer()
    {
        std::cout << "Starting timer..." << std::endl;
        timer_Name = "";
        start_Time = std::chrono::high_resolution_clock::now();
    }

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
        std::cout << "   " << s << " s" << std::endl
                  << std::endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_Time;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_Time;
    std::string timer_Name;
};

int recursive_function(int repeats, int &val)
{
    if (repeats > 0)
    {
        val += repeats;
        recursive_function(repeats - 1, val);
    }
    return val;
}

int main()
{
    std::cout << "iter value: " << iter << std::endl
              << std::endl;

    {
        Timer timer("iterative val"); // Now it is defined, literally just whack this at the start of the scope you plan to time
        int val = 0;
        for (int i = 1; i <= iter; i++)
        {
            val += i;
        }
        std::cout << "val: " << val << std::endl;
    }

    {
        Timer timer("recursive val");
        int val = 0;
        recursive_function(iter, val);
        std::cout << "val: " << val << std::endl;
    }

    std::cout << "Notice how much slower the recursive version is (the difference between the two increases faster the larger the difference due to a phenomena known as time complexity)" << std::endl;
}