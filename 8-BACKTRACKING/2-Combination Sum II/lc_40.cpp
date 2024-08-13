#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    void solve(vector<int> &candidates, int target, int idx, vector<vector<int>> &result, vector<int> &curr)
    {
        if (target < 0)
        {
            return;
        }

        if (target == 0)
        {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            curr.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, result, curr);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        int idx = 0;
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); // to skip duplicates
        solve(candidates, target, idx, result, curr);

        return result;
    }
};