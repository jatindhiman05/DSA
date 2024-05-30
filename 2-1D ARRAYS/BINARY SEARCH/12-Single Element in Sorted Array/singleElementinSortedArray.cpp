#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        int l = 0;
        int h = n - 1;

        while (l < h)
        {
            int mid = l + (h - l) / 2;

            bool isEven = (h - mid) % 2 == 0;

            if (nums[mid] == nums[mid + 1])
            {
                if (isEven)
                {
                    l = mid + 2;
                }
                else
                {
                    h = mid - 1;
                }
            }
            else
            {
                if (isEven)
                {
                    h = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }

        return nums[h];
    }
};