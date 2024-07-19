// https://www.naukri.com/code360/problems/break-and-merge_2684591?
#include <iostream>
#include <vector>
using namespace std;

int countMaxSubarray(vector<int> &A)
{
    int ans = 0;
    int max_val = -1;
    for (int i = 0; i < A.size(); i++)
    {
        max_val = max(max_val, A[i]);
        if (max_val == i)
        {
            ans++;
        }
    }

    return ans;
}
