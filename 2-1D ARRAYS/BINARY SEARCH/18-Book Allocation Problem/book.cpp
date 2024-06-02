#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool isPossible(int A[], int N, int M, int sol)
    {
        int pageSum = 0;
        int count = 1;

        for (int i = 0; i < N; i++)
        {
            if (A[i] > sol)
            {
                return false;
            }
            if (pageSum + A[i] > sol)
            {
                count++;
                pageSum = A[i];
                if (count > M)
                {
                    return false;
                }
            }
            else
            {
                pageSum += A[i];
            }
        }

        return true;
    }
    // Function to find minimum number of pages.
    int findPages(int A[], int N, int M)
    {
        if (M > N)
        {
            return -1;
        }

        int start = 0;
        int end = accumulate(A, A + N, 0);

        int mid = start + (end - start) / 2;

        int ans = -1;

        while (start <= end)
        {
            if (!isPossible(A, N, M, mid))
            {
                start = mid + 1;
            }
            else
            {
                ans = mid;
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }

        return ans;
    }
};