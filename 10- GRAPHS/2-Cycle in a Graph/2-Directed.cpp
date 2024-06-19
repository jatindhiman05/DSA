#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isCycle(vector<int> adj[], int u, vector<bool> &visited, vector<bool> &inRecursion)
    {
        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : adj[u])
        {
            if (!visited[v] && isCycle(adj, v, visited, inRecursion))
            {
                return true;
            }
            else if (inRecursion[v])
            {
                return true;
            }
        }

        inRecursion[u] = false;

        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && isCycle(adj, i, visited, inRecursion))
            {
                return true;
            }
        }

        return false;
    }
};