#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int find_min_idx(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;

        int mid = start + (end - start) / 2;

        while (start < end)
        {
            if (nums[mid] > nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
            mid = start + (end - start) / 2;
        }

        return end;
    }

    int binarySearch(vector<int> &nums, int start, int end, int target)
    {
        int mid = start + (end - start) / 2;

        while (start <= end)
        {
            if (nums[mid] == target)
            {
                return mid;
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

        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int min_idx = find_min_idx(nums, target);
        int start = 0;
        int end = nums.size() - 1;

        // nums is sorted before and after min_idx !!
        int idx = binarySearch(nums, 0, min_idx - 1, target);

        if (idx != -1)
        {
            return idx;
        }

        idx = binarySearch(nums, min_idx, nums.size() - 1, target);

        return idx;
    }
};
