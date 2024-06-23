// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        priority_queue<pair<int, int>> max_pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;

        int i = 0;
        int j = 0;
        int maxSubarrayLen = 0;

        while (j < nums.size())
        {
            max_pq.push({nums[j], j});
            min_pq.push({nums[j], j});

            while (max_pq.top().first - min_pq.top().first > limit)
            { // means shrink window

                i = min(max_pq.top().second, min_pq.top().second) + 1; // imp

                // remove elem from pq having idx less than i
                while (max_pq.top().second < i)
                {
                    max_pq.pop();
                }

                while (min_pq.top().second < i)
                {
                    min_pq.pop();
                }
            }

            maxSubarrayLen = max(maxSubarrayLen, j - i + 1);
            j++;
        }

        return maxSubarrayLen;
    }
};