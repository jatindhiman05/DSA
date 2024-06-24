// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int>
    dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // {dist,node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> result(V, INT_MAX);

        result[S] = 0;

        pq.push({0, S});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &v : adj[node])
            {
                int adjNode = v[0];
                int adjWt = v[1];

                if (d + adjWt < result[adjNode])
                {
                    result[adjNode] = d + adjWt;
                    pq.push({d + adjWt, adjNode});
                }
            }
        }

        return result;
    }
};