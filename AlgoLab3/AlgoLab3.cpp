#include <iostream>
#include "TestTime.h"
#include <string>

#include <future>
#include <thread>

int main()
{
    srand(time(0));

    std::cout << "TestForwardQuickSort: " << std::to_string(TestTime::TestForwardQuickSort()) << std::endl;
    std::cout << "TestReverseQuickSort: " << std::to_string(TestTime::TestReverseQuickSort()) << std::endl;

    std::promise<double> thread1Promise;
    std::future<double> thread1Future = thread1Promise.get_future();
    std::thread myThread1([&thread1Promise]()
        {
            thread1Promise.set_value(TestTime::TestForwardInsertionSort());
        });

    std::promise<double> thread2Promise;
    std::future<double> thread2Future = thread2Promise.get_future();
    std::thread myThread2([&thread2Promise]()
        {
            thread2Promise.set_value(TestTime::TestReverseInsertionSort());
        });

    myThread1.join();
    myThread2.join();

    std::cout << "TestForwardInsertionSort: " << std::to_string(thread1Future.get()) << std::endl;
    std::cout << "TestReverseInsertionSort: " << std::to_string(thread2Future.get()) << std::endl;
    
    //double sum = 0.0;
    //for (int i = 0; i < 100; i++)
    //{
    //    sum += TestTime::TestForwardQuickSort();
    //}
    //std::cout << /*"TestForwardQuickSort: " << */std::to_string(sum / 100.0) << std::endl;

    //sum = 0.0;
    //for (int i = 0; i < 100; i++)
    //{
    //    sum += TestTime::TestReverseQuickSort();
    //}
    //std::cout << /*"TestReverseQuickSort: " << */std::to_string(sum / 100.0) << std::endl;

    //sum = 0.0;
    //for (int i = 0; i < 100; i++)
    //{
    //    sum += TestTime::TestForwardInsertionSort();
    //}
    //std::cout << /*"TestForwardInsertionSort: " << */std::to_string(sum / 100.0) << std::endl;

    //sum = 0.0;
    //for (int i = 0; i < 100; i++)
    //{
    //    sum += TestTime::TestReverseInsertionSort();
    //}
    //std::cout << /*"TestReverseInsertionSort: " << */std::to_string(sum / 100.0) << std::endl;


    return 0;
}
