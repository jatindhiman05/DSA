#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<int> &visited)
    {
        visited[u] = true;

        for (auto &v : adj[u])
        {
            if (!visited[v])
            {
                DFS(adj, v, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> answer(n, vector<int>{});

        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> visited(n, false);
            DFS(adj, i, visited);

            vector<int> nodeAns;
            for (int j = 0; j < n; j++)
            {
                if (visited[j] && j != i)
                {
                    nodeAns.push_back(j);
                }
            }

            answer[i] = nodeAns;
        }

        return answer;
    }
};