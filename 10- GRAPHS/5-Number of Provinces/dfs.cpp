// https://www.geeksforgeeks.org/problems/number-of-provinces/1
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited)
    {
        visited[u] = true;

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                DFS(adj, v, visited);
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
                DFS(adjList, i, visited);
            }
        }

        return provinces;
    }
};