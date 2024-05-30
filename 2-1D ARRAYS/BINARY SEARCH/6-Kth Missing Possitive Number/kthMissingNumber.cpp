#include <iostream>
#include <vector>
using namespace std;

// brute force O(n)
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int num = 1;
        int i = 0;

        while (i < arr.size() && k > 0)
        {
            if (arr[i] == num)
            {
                i++;
            }
            else
            {
                k--;
            }
            num++;
        }

        while (k--)
        {
            num++;
        }

        return num - 1;
    }
};

// optimal O(logn)
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();

        int start = 0;
        int end = n - 1;

        int mid = start + (end - start) / 2;

        while (start <= end)
        {
            int kitne_missing_tillMid = arr[mid] - (mid + 1);

            if (kitne_missing_tillMid < k)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }

        return start + k;
    }
};