// https://www.geeksforgeeks.org/problems/prerequisite-tasks/1
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkCycleHelper(unordered_map<int, vector<int>> &adjList, int u, vector<int> &visited, vector<int> &inRecursion)
    {
        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : adjList[u])
        {
            if (!visited[v] && checkCycleHelper(adjList, v, visited, inRecursion))
            {
                return true;
            }
            else if (inRecursion[v])
            {
                return true;
            }
        }

        inRecursion[u] = false;

        return false;
    }
    bool checkCycle(unordered_map<int, vector<int>> &adjList, int V)
    {
        vector<int> visited(V, false);
        vector<int> inRecursion(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && checkCycleHelper(adjList, i, visited, inRecursion))
            {
                return true;
            }
        }

        return false;
    }
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adjList;

        for (auto &edge : prerequisites)
        {
            int u = edge.first;
            int v = edge.second;

            adjList[u].push_back(v);
        }

        return !checkCycle(adjList, N);
    }
};