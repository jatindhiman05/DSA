// https://www.geeksforgeeks.org/problems/bipartite-graph/1
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkBipartiteDFS(vector<int> adj[], int currNode, vector<int> &color, int currColor)
    {
        color[currNode] = currColor;

        for (int &v : adj[currNode])
        {
            if (color[v] == currColor)
            {
                return false;
            }

            if (color[v] == -1)
            {
                int currColorV = 1 - currColor;

                if (!checkBipartiteDFS(adj, v, color, currColorV))
                {
                    return false;
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
                if (!checkBipartiteDFS(adj, i, color, 0))
                {
                    return false;
                }
            }
        }

        return true;
    }
};