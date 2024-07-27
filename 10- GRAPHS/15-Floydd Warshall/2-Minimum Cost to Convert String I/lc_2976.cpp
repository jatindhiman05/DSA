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
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        int n = original.size();
        vector<vector<int>> adj(26, vector<int>(26, INT_MAX)); // 26 for all lowercase letters

        // self loop
        for (int i = 0; i < 26; i++)
        {
            adj[i][i] = 0;
        }

        // fill cost matrix
        for (int i = 0; i < original.size(); i++)
        {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            adj[s][t] = min(adj[s][t], cost[i]); // duplicate
        }

        // this matrix stores all pairs shortest paths
        vector<vector<int>> shortest_matrix(26, vector<int>(26, INT_MAX));

        allPaths(adj, shortest_matrix, 26);

        long long ans = 0;

        for (int i = 0; i < source.length(); i++)
        {
            if (source[i] == target[i])
            {
                continue;
            }

            if (shortest_matrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
            {
                return -1;
            }

            ans += shortest_matrix[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
    }
};