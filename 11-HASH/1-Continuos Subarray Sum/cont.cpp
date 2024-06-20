#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// sliding window -> NO
// brute force -> O(n^2)

// 31 % 4 = 3
// (31 + 8) % 4 = 3 => 8 must be divisible by 4 
// Create mappin remain <-> idx
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> mp;

        mp[0] = -1;

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            int remainder = sum % k;

            if (mp.find(remainder) != mp.end())
            {

                if (i - mp[remainder] >= 2)
                    return true;
            }
            else
            {
                mp[remainder] = i;
            }
        }
        return false;
    }
};