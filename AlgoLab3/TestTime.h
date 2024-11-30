#pragma once
#include <chrono>
#include "Sort.h"

static class TestTime
{
private:
    static const int size = 1000;
public:
    static double TestForwardQuickSort()
    {
        int a[size];
        for (int& x : a)
        {
            x = rand() % 1000000;
        }

        std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
        Sort::QuickSort(a, a + size, [](int a, int b) { return a < b; });
        std::chrono::duration<double> duration = std::chrono::system_clock::now() - start;

       /* for (const int& x : a) 
        {
            std::cout << x << ",";
        }
        std::cout << std::endl;*/

        return duration.count();
    }

    static double TestReverseQuickSort()
    {
        int a[size];
        for (int& x : a)
        {
            x = rand() % 1000000;
        }

        std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
        Sort::QuickSort(a, a + size, [](int a, int b) { return a > b; });
        std::chrono::duration<double> duration = std::chrono::system_clock::now() - start;

        /*for (const int& x : a)
        {
            std::cout << x << ",";
        }
        std::cout << std::endl;*/

        return duration.count();
    }

    static double TestForwardInsertionSort()
    {
        int a[size];
        for (int& x : a)
        {
            x = rand() % 1000000;
        }

        std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
        Sort::InsertionSort(a, a + size, [](int a, int b) { return a < b; });
        std::chrono::duration<double> duration = std::chrono::system_clock::now() - start;

        /*for (const int& x : a)
        {
            std::cout << x << ",";
        }
        std::cout << std::endl;*/

        return duration.count();
    }

    static double TestReverseInsertionSort()
    {
        int a[size];
        for (int& x : a)
        {
            x = rand() % 1000000;
        }

        std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
        Sort::InsertionSort(a, a + size, [](int a, int b) { return a > b; });
        std::chrono::duration<double> duration = std::chrono::system_clock::now() - start;

        /*for (const int& x : a)
        {
            std::cout << x << ",";
        }
        std::cout << std::endl;*/

        return duration.count();
    }
};