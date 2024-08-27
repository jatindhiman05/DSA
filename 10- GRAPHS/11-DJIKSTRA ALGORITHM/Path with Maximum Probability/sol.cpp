// https://leetcode.com/problems/path-with-maximum-probability/description/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        unordered_map<int, vector<pair<int, double>>> adjList;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back({v, succProb[i]});
            adjList[v].push_back({u, succProb[i]});
        }

        vector<double> dist(n, 0);
        dist[start_node] = 1.0;

        priority_queue<pair<double, int>> pq;

        pq.push({1.0, start_node});

        // modified djikstra
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            for (auto &nbr : adjList[top.second])
            {
                if (top.first * nbr.second > dist[nbr.first])
                {
                    dist[nbr.first] = top.first * nbr.second;
                    pq.push({dist[nbr.first], nbr.first});
                }
            }
        }

        return dist[end_node];
    }
};