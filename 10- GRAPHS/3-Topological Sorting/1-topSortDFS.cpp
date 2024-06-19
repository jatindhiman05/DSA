// https://www.geeksforgeeks.org/problems/topological-sort/1
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    void DfS(vector<int> adj[], int u, vector<bool> &visited, stack<int> &st)
    {
        visited[u] = true;

        for (int &v : adj[u])
        {
            if (!visited[v])
            {
                DfS(adj, v, visited, st);
            }
        }

        st.push(u);
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DfS(adj, i, visited, st);
            }
        }

        vector<int> result;

        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};