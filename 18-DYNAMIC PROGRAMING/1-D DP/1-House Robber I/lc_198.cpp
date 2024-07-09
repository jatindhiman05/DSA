#include <iostream>
#include <vector>
using namespace std;

// Recursion and Memoziation

class Solution
{
public:
    int t[101];
    int choryKaro(vector<int> &nums, int idx)
    {
        if (idx >= nums.size())
        {
            return 0;
        }

        if (t[idx] != -1)
        {
            return t[idx];
        }

        int inc = nums[idx] + choryKaro(nums, idx + 2);
        int exc = choryKaro(nums, idx + 1);

        return t[idx] = max(inc, exc);
    }
    int rob(vector<int> &nums)
    {
        memset(t, -1, sizeof(t));
        return choryKaro(nums, 0);
    }
};

// bottom up

class Solution
{
public:
    int t[101];
    int choryKaro_bottomUp(vector<int> &nums)
    {
        t[0] = 0;
        t[1] = nums[0];

        for (int i = 2; i <= nums.size(); i++)
        {
            int steal = nums[i - 1] + t[i - 2];
            int skip = t[i - 1];
            t[i] = max(steal, skip);
        }

        return t[nums.size()];
    }

    int rob(vector<int> &nums)
    {
        memset(t, -1, sizeof(t));
        return choryKaro_bottomUp(nums);
    }
};