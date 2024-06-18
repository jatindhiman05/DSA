#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// using DFS
class Solution
{
public:
    bool isCycleHelper(vector<int> adj[], int u, int parent, vector<bool> &visited)
    {
        visited[u] = true;

        for (int &v : adj[u])
        {
            if (v == parent)
            {
                continue;
            }

            if (visited[v])
            {
                return true;
            }

            if (isCycleHelper(adj, v, u, visited))
            {
                return true;
            }
        }

        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && isCycleHelper(adj, i, -1, visited))
            {
                return true;
            }
        }

        return false;
    }
};

// using BFS

class Solution
{
public:
    bool isCycleHelper(vector<int> adj[], int u, vector<bool> &visited)
    {
        queue<pair<int, int>> q;
        q.push({u, -1});
        visited[u] = true;

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int src = p.first;
            int parent = p.second;

            for (int &v : adj[src])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push({v, src});
                }
                else if (v != parent)
                {
                    return true;
                }
            }
        }

        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && isCycleHelper(adj, i, visited))
            {
                return true;
            }
        }

        return false;
    }
};