#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(int n, int k, vector<int> Arr)
{
    priority_queue<int> pq;

    for (int i = 0; i < Arr.size(); i++)
    {
        pq.push(Arr[i]);

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    return pq.top();
}