// https://leetcode.com/problems/count-number-of-nice-subarrays/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int count = 0;
        int odd_count = 0;
        int result = 0;

        int i = 0;
        int j = 0;

        while (j < nums.size())
        {
            if (nums[j] % 2 != 0)
            {
                odd_count++;
                count = 0;
            }

            while (odd_count == k)
            {
                if (nums[i] % 2 != 0)
                {
                    odd_count--;
                }
                i++;
                count++;
            }

            result += count;
            j++;
        }

        return result;
    }
};