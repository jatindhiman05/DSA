// https://www.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1?
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    {

        sort(arr, arr + n);

        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == 0)
                {
                    return true;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        return false;
    }
};
