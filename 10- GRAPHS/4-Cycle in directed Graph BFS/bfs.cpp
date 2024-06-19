#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
        queue<int> q;

        for (int u = 0; u < V; u++)
        {
            for (int &v : adj[u])
            {
                indegree[v]++;
            }
        }

        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                count++;
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int &v : adj[u])
            {
                indegree[v]--;

                if (indegree[v] == 0)
                {
                    count++;
                    q.push(v);
                }
            }
        }

        return count == V ? false : true;
    }
};