#include <iostream>
#include <vector>
using namespace std;

// O(n)
class Solution
{
public:
    int findKRotation(int arr[], int n)
    {
        int small_idx = -1;
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                small_idx = i;
            }
        }

        return small_idx;
    }
};

// O(logn) -> similar to find minimum in rotated sorted array
class Solution
{
public:
    int findKRotation(int arr[], int n)
    {
        int start = 0;
        int end = n - 1;

        int mid = start + (end - start) / 2;

        while (start < end)
        {
            if (arr[mid] > arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
            mid = start + (end - start) / 2;
        }

        return mid;
    }
};
