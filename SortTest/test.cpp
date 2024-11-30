#include "pch.h"
#include "../AlgoLab3/Sort.h"

TEST(InsertionSort, Forward)
{
    const int size = 40;
    int a[size];
    for (int& x : a)
    {
        x = rand() % 1000000;
    }
    Sort::InsertionSort(a, a + size, [](int a, int b) { return a < b; });

    for (int i = 1; i < size; i++)
    {
        ASSERT_TRUE(a[i] >= a[i - 1]);
    }
}

TEST(InsertionSort, Reverse)
{
    const int size = 40;
    int a[size];
    for (int& x : a)
    {
        x = rand() % 1000000;
    }
    Sort::InsertionSort(a, a + size, [](int a, int b) { return a > b; });

    for (int i = 1; i < size; i++)
    {
        ASSERT_TRUE(a[i] <= a[i - 1]);
    }
}

TEST(QuickSort, Forward000008)
{
    const int size = 8;
    int a[size];
    for (int& x : a)
    {
        x = rand() % 1000000;
    }
    Sort::QuickSort(a, a + size, [](int a, int b) { return a < b; });

    for (int i = 1; i < size; i++)
    {
        ASSERT_TRUE(a[i] >= a[i - 1]);
    }
}

TEST(QuickSort, Reverse000008)
{
    const int size = 8;
    int a[size];
    for (int& x : a)
    {
        x = rand() % 1000000;
    }
    Sort::QuickSort(a, a + size, [](int a, int b) { return a > b; });

    for (int i = 1; i < size; i++)
    {
        ASSERT_TRUE(a[i] <= a[i - 1]);
    }
}

TEST(QuickSort, Forward000064)
{
    const int size = 64;
    int a[size];
    for (int& x : a)
    {
        x = rand() % 1000000;
    }
    Sort::QuickSort(a, a + size, [](int a, int b) { return a < b; });

    for (int i = 1; i < size; i++)
    {
        ASSERT_TRUE(a[i] >= a[i - 1]);
    }
}

TEST(QuickSort, Reverse000064)
{
    const int size = 64;
    int a[size];
    for (int& x : a)
    {
        x = rand() % 1000000;
    }
    Sort::QuickSort(a, a + size, [](int a, int b) { return a > b; });

    for (int i = 1; i < size; i++)
    {
        ASSERT_TRUE(a[i] <= a[i - 1]);
    }
}

TEST(QuickSort, Forward001000)
{
    const int size = 1000;
    int a[size];
    for (int& x : a)
    {
        x = rand() % 1000000;
    }
    Sort::QuickSort(a, a + size, [](int a, int b) { return a < b; });

    for (int i = 1; i < size; i++)
    {
        ASSERT_TRUE(a[i] >= a[i - 1]);
    }
}

TEST(QuickSort, Reverse001000)
{
    const int size = 1000;
    int a[size];
    for (int& x : a)
    {
        x = rand() % 1000000;
    }
    Sort::QuickSort(a, a + size, [](int a, int b) { return a > b; });

    for (int i = 1; i < size; i++)
    {
        ASSERT_TRUE(a[i] <= a[i - 1]);
    }
}

TEST(QuickSort, Forward010000)
{
    const int size = 10000;
    int a[size];
    for (int& x : a)
    {
        x = rand() % 1000000;
    }
    Sort::QuickSort(a, a + size, [](int a, int b) { return a < b; });

    for (int i = 1; i < size; i++)
    {
        ASSERT_TRUE(a[i] >= a[i - 1]);
    }
}

TEST(QuickSort, Reverse010000)
{
    const int size = 10000;
    int a[size];
    for (int& x : a)
    {
        x = rand() % 1000000;
    }
    Sort::QuickSort(a, a + size, [](int a, int b) { return a > b; });

    for (int i = 1; i < size; i++)
    {
        ASSERT_TRUE(a[i] <= a[i - 1]);
    }
}

TEST(QuickSort, Forward100000)
{
    const int size = 100000;
    int a[size];
    for (int& x : a)
    {
        x = rand() % 1000000;
    }
    Sort::QuickSort(a, a + size, [](int a, int b) { return a < b; });

    for (int i = 1; i < size; i++)
    {
        ASSERT_TRUE(a[i] >= a[i - 1]);
    }
}

TEST(QuickSort, Reverse100000)
{
    const int size = 100000;
    int a[size];
    for (int& x : a)
    {
        x = rand() % 1000000;
    }
    Sort::QuickSort(a, a + size, [](int a, int b) { return a > b; });

    for (int i = 1; i < size; i++)
    {
        ASSERT_TRUE(a[i] <= a[i - 1]);
    }
}