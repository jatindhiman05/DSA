// lc2461
#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int i = 0, j = 0;
        long long result = 0;
        long long sum = 0;
        unordered_set<int> st;

        while (j < nums.size())
        {
            while (st.count(nums[j]))
            {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            sum += nums[j];
            st.insert(nums[j]);

            if (j - i + 1 == k)
            {
                result = max(result, sum);
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
        }

        return result;
    }
};
