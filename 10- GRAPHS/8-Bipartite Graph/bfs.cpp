// https://www.geeksforgeeks.org/problems/bipartite-graph/1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool checkBipartiteBFS(vector<int> adj[], int currNode, vector<int> &color, int currColor)
    {
        color[currNode] = currColor;
        queue<int> q;
        q.push(currNode);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (int &v : adj[front])
            {
                if (color[v] == color[front])
                {
                    return false;
                }

                if (color[v] == -1)
                {
                    color[v] = 1 - color[front];

                    q.push(v);
                }
            }
        }

        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!checkBipartiteBFS(adj, i, color, 0))
                {
                    return false;
                }
            }
        }

        return true;
    }
};