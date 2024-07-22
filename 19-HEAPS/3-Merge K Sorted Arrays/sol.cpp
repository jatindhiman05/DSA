// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto row : arr)
        {
            for (auto ele : row)
            {
                pq.push(ele);
            }
        }

        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};