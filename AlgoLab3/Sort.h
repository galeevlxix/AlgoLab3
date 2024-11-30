#pragma once
#include <utility>

static class Sort
{
private:
    static const int threshold = 16;

    template<typename T>
    static void MoveSwap(T& a, T& b)
    {
        T temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

    template<typename T, typename Compare>
    static T* GetMedian(T* first, T* mid, T* last, Compare comp)
    {
        if (comp(*mid, *first)) MoveSwap(*mid, *first);
        if (comp(*last, *first)) MoveSwap(*last, *first);
        if (comp(*last, *mid)) MoveSwap(*last, *mid);

        return mid;
    }

public:
    template<typename T, typename Compare>
    static void InsertionSort(T* first, T* last, Compare comp)
    {
        for (T* i = first + 1; i < last; ++i)
        {
            T temp = std::move(*i);
            T* j = i;
            while (j > first && comp(temp, *(j - 1)))
            {
                *j = std::move(*(j - 1));
                --j;
            }
            *j = std::move(temp);
        }
    }

    template<typename T, typename Compare>
    static void QuickSort(T* first, T* last, Compare comp)
    {
        while (last - first > 1)
        {
            if (last - first <= threshold)
            {
                InsertionSort(first, last, comp);
                return;
            }

            T* mid = first + (last - first) / 2;
            T* pivot = GetMedian(first, mid, last - 1, comp);

            MoveSwap(*pivot, *(last - 1));

            T* left = first;
            T* rigth = last - 1;
            T* pivotValue = rigth;

            while (true)
            {
                while (comp(*left, *pivotValue)) ++left;
                while (comp(*pivotValue, *(--rigth)))
                {
                    if (rigth == first) break;
                }
                if (left >= rigth) break;
                MoveSwap(*left, *rigth);
                ++left;
            }

            MoveSwap(*left, *(last - 1));

            T* leftEnd = left;
            T* rightStart = left + 1;

            if (leftEnd - first < last - rightStart)
            {
                QuickSort(first, leftEnd, comp);
                first = rightStart;
            }
            else
            {
                QuickSort(rightStart, last, comp);
                last = leftEnd;
            }
        }
    }
};