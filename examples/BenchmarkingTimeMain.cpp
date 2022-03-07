// See BenchmarkingTime.cpp

#include "BenchmarkingTime.cpp"

#include <iostream>

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
    int iter = 5000; // Try modding this to different +ve integer values to see how the difference changes

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
    return 0;
}