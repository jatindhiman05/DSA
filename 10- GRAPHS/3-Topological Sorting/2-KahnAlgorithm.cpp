// top sort using BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
        queue<int> q;

        // fill indegree vector
        for (int u = 0; u < V; u++)
        {
            for (int &v : adj[u])
            {
                indegree[v]++;
            }
        }

        // fill queue with nodes having indegree zero
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty())
        {
            int u = q.front();
            result.push_back(u);
            q.pop();

            for (int &v : adj[u])
            {
                indegree[v]--;

                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        return result;
    }
};