// https://leetcode.com/problems/maximum-total-importance-of-roads/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> degree(n, 0);

        for (auto &edge : roads)
        {
            int u = edge[0];
            int v = edge[1];

            degree[u]++;
            degree[v]++;
        }

        sort(degree.begin(), degree.end());

        long long maxImportance = 0;
        long long value = 1;

        for (int i = 0; i < n; i++)
        {
            maxImportance += (degree[i] * value);
            value++;
        }

        return maxImportance;
    }
};