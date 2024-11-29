#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    int solve(vector<vector<int>> &items, int q)
    {
        int start = 0;
        int end = items.size() - 1;
        int mid = start + (end - start) / 2;
        int ans = 0;

        while (start <= end)
        {
            if (items[mid][0] <= q)
            {
                ans = max(ans, items[mid][1]);
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }

        return ans;
    }

public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        sort(items.begin(), items.end());

        vector<int> result;
        int maxB = items[0][1];
        for (int i = 0; i < items.size(); i++)
        {
            maxB = max(maxB, items[i][1]);
            items[i][1] = maxB;
        }

        for (auto &q : queries)
        {
            int ans = solve(items, q);
            result.push_back(ans);
        }

        return result;
    }
};