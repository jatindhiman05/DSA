#include <iostream>
#include <vector>
using namespace std;
// Find Minimum in Rotated Sorted Array
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();

        int l = 0;
        int h = n - 1;

        int mid = l + (h - l) / 2;

        while (l < h)
        {
            if (nums[mid] > nums[h])
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }

            mid = l + (h - l) / 2;
        }

        return nums[h];
    }
};