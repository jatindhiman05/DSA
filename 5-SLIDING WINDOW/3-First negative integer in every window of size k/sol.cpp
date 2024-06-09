// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    queue<long long> q;
    long long int i = 0;
    long long int j = 0;

    vector<long long> result;

    while (j < N)
    {
        if (A[j] < 0)
        {
            q.push(A[j]);
        }

        if (j - i + 1 == K)
        {
            if (!q.empty())
            {
                result.push_back(q.front());
            }
            else
            {
                result.push_back(0);
            }

            // window shift karni hai
            if (A[i] < 0 && !q.empty())
            {
                q.pop();
            }
            i++;
        }
        j++;
    }

    return result;
}