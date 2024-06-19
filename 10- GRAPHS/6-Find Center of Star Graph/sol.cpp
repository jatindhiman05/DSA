#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// center will have highest indegree ?
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        unordered_map<int, int> indegree;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            indegree[u]++;
            indegree[v]++;
        }

        int nodeNo;
        int freq = 0;

        for (auto &i : indegree)
        {
            if (i.second > freq)
            {
                freq = i.second;
                nodeNo = i.first;
            }
        }

        return nodeNo;
    }
};