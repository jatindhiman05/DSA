#include <iostream>
using namespace std;

// brute force -> O(n^2)
class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {

        long long sum = 0;

        long long max_sum = arr[0];

        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                max_sum = max(max_sum, sum);
            }
        }

        return max_sum;
    }
};

// optimal one -> O(n)

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {

        long long sum = 0;

        long long max_sum = arr[0];

        for (int i = 0; i < n; i++)
        {
            sum += arr[i]; // step-1
            
            max_sum = max(max_sum, sum); // step-2 

            if (sum < 0) // step - 3
            {
                sum = 0;
            }
        }

        return max_sum;
    }
};