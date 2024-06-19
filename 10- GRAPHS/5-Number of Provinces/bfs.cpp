// https://www.geeksforgeeks.org/problems/number-of-provinces/1
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    void BFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited)
    {
        visited[u] = true;
        queue<int> q;

        q.push(u);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int &v : adj[curr])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    int numProvinces(vector<vector<int>> &adj, int V)
    {
        unordered_map<int, vector<int>> adjList;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int provinces = 0;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                provinces++;
                BFS(adjList, i, visited);
            }
        }

        return provinces;
    }
};