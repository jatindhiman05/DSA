// https://leetcode.com/problems/majority-element-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int can1 = -1;
        int can2 = -1;
        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == can1)
            {
                count1++;
            }
            else if (nums[i] == can2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                can1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                can2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        vector<int> result;
        count1 = 0;
        count2 = 0;
        for (auto &num : nums)
        {
            if (num == can1)
            {
                count1++;
            }
            else if (num == can2)
            {
                count2++;
            }
        }

        if (count1 > n / 3)
            result.push_back(can1);
        if (count2 > n / 3)
            result.push_back(can2);

        return result;
    }
};
