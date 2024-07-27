#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    void allPaths(vector<vector<int>> &cost, vector<vector<int>> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[i][j] = cost[i][j];
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (A[i][k] != INT_MAX && A[k][j] != INT_MAX)
                    {
                        A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                    }
                }
            }
        }
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

        // self loop
        for (int i = 0; i < n; i++)
        {
            cost[i][i] = 0;
        }

        // fill cost matrix
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            cost[u][v] = wt;
            cost[v][u] = wt;
        }

        // this matrix stores all pairs shortest paths
        vector<vector<int>> shortest_matrix(n, vector<int>(n, INT_MAX));

        allPaths(cost, shortest_matrix, n);

        // count for, how many nodes for a given node have dist <= distanceThreshold
        vector<int> count(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (shortest_matrix[i][j] <= distanceThreshold)
                {
                    count[i]++;
                }
            }
        }

        int ans = -1;
        int mini = INT_MAX;

        // find node with minimum count
        for (int i = 0; i < n; i++)
        {
            if (count[i] <= mini)
            {
                mini = count[i];
                ans = i;
            }
        }

        return ans;
    }
};
