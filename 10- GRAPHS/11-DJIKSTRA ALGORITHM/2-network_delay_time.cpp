// https://leetcode.com/problems/network-delay-time/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto &edge : times)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        // {dist,node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> result(n + 1, INT_MAX);

        result[k] = 0;

        pq.push({0, k});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &v : adj[node])
            {
                int nbr = v.first;
                int wt = v.second;

                if (d + wt < result[nbr])
                {
                    result[nbr] = d + wt;
                    pq.push({d + wt, nbr});
                }
            }
        }

        int res = INT_MIN;

        for (int i = 1; i <= n; i++)
        {
            res = max(res, result[i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};