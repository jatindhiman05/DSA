// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ (lc-34)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findLeftMost(vector<int> &nums, int target, int n)
    {
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start) / 2;

        int left_most_idx = -1;

        while (start <= end)
        {
            if (nums[mid] == target)
            {
                left_most_idx = mid;
                end = mid - 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }

        return left_most_idx;
    }
    int findRightMost(vector<int> &nums, int target, int n)
    {
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start) / 2;

        int right_most_idx = -1;

        while (start <= end)
        {
            if (nums[mid] == target)
            {
                right_most_idx = mid;
                start = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }

        return right_most_idx;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();

        int left_most = findLeftMost(nums, target, n);
        int right_most = findRightMost(nums, target, n);

        return {left_most, right_most};
    }
};