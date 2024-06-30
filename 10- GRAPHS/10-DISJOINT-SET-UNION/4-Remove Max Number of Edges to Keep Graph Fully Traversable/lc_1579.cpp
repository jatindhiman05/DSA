#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU
{
    vector<int> rank;
    vector<int> parent;
    int components;

public:
    DSU(int n)
    {
        rank.resize(n + 1);
        parent.resize(n + 1);
        components = n;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }
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
        else if (rank[x_parent] > rank[y_parent])
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
        components--;
    }

    bool isSingleComponent()
    {
        return components == 1;
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DSU alice(n);
        DSU bob(n);

        int edgeCount = 0;

        // process type 3 first
        sort(edges.begin(), edges.end(), [](auto vec1, auto vec2)
             { return vec1[0] > vec2[0]; });

        for (auto &edge : edges)
        {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (type == 3)
            {
                bool edgeAdded = false;

                if (alice.find(u) != alice.find(v))
                {
                    // u and v in diff sets
                    alice.Union(u, v);
                    edgeAdded = true;
                }

                if (bob.find(u) != bob.find(v))
                {
                    bob.Union(u, v);
                    edgeAdded = true;
                }

                if (edgeAdded)
                    edgeCount++;
            }
            else if (type == 2)
            {
                if (bob.find(u) != bob.find(v))
                {
                    bob.Union(u, v);
                    edgeCount++;
                }
            }
            else
            {
                if (alice.find(u) != alice.find(v))
                {
                    alice.Union(u, v);
                    edgeCount++;
                }
            }
        }

        if (alice.isSingleComponent() && bob.isSingleComponent())
        {
            return edges.size() - edgeCount;
        }

        return -1;
    }
};