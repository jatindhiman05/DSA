// https://www.geeksforgeeks.org/problems/prerequisite-tasks/1
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    bool checkCycle(unordered_map<int, vector<int>> &adjList, int V)
    {
        vector<int> inDegree(V, 0);

        for (int u = 0; u < V; u++)
        {
            for (auto &v : adjList[u])
            {
                inDegree[v]++;
            }
        }

        int count = 0;
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                count++;
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (int &v : adjList[front])
            {
                inDegree[v]--;

                if (inDegree[v] == 0)
                {
                    count++;
                    q.push(v);
                }
            }
        }

        return count == V ? false : true;
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