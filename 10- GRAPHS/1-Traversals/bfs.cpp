#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        queue<int> q;
        vector<bool> visited(V, false);
        vector<int> result;
        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int currNode = q.front();
            q.pop();
            result.push_back(currNode);

            for (auto &nbr : adj[currNode])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }

        return result;
    }
};