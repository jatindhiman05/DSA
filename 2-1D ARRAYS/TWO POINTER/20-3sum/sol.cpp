#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    void twoSum(vector<int> &nums, int target, int i, int j, vector<vector<int>> &ans)
    {
        while (i < j)
        {
            if (nums[i] + nums[j] > target)
            {
                j--;
            }
            else if (nums[i] + nums[j] < target)
            {
                i++;
            }
            else
            {

                while (i < j && nums[i] == nums[i + 1])
                    i++;

                while (i < j && nums[j] == nums[j - 1])
                    j--;

                ans.push_back({-target, nums[i], nums[j]});

                i++;
                j--;
            }
        }
    }

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.clear();
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int n1 = nums[i];
            int target = -n1;

            twoSum(nums, target, i + 1, nums.size() - 1, ans);
        }

        return ans;
    }
};