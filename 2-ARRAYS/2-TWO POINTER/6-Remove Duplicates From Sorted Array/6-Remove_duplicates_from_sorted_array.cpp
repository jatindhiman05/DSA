// https://leetcode.com/problems/remove-duplicates-from-sorted-array/ (lc - > 26)
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();

        int i = 0;
        int j = i + 1;

        while (j < n)
        {
            if (nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }

            j++;
        }

        return i + 1;
    }
};