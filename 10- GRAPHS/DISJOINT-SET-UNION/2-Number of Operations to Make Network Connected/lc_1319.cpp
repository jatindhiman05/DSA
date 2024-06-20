// https://www.geeksforgeeks.org/problems/minimize-connections/1
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
        {
            return;
        }

        if (rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int minimumConnections(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
        {
            return -1;
        }

        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }

        int components = n;

        for (auto &edge : connections)
        {
            if (find(edge[0]) != find(edge[1]))
            {
                Union(edge[0], edge[1]);

                components--;
            }
        }

        return components - 1;
    }
};
