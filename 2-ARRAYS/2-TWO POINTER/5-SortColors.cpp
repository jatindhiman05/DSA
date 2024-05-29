// https://leetcode.com/problems/sort-colors/ leetcode -> 75
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int idx = 0;
        int start = 0;
        int end = nums.size() - 1;

        while (idx <= end) // imp !!!
        {
            if (nums[idx] == 0)
            {
                swap(nums[idx], nums[start]);
                start++;
                idx++;
            }
            else if (nums[idx] == 2)
            {
                swap(nums[idx], nums[end]);
                end--;
                // imp
                // no need of idx++
            }
            else
            {
                idx++;
            }
        }
    }
};

// We don’t do index++ when nums[index] == 2 because we don’t know after swapping at index 
// will it be 0/1/2 but in case of nums[index] == 0 /1 we are sure that it will be 0 or 1