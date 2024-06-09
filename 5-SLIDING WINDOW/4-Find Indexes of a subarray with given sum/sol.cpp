// https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        long long currSum = 0;
        int i = 0;
        int j = 0;

        while (j < n)
        {
            currSum += arr[j];
            // shrink window
            while (currSum > s && i < j)
            {
                currSum -= arr[i];
                i++;
            }

            if (currSum == s)
            {
                return {i + 1, j + 1};
            }
            j++;
        }

        return {-1};
    }
};