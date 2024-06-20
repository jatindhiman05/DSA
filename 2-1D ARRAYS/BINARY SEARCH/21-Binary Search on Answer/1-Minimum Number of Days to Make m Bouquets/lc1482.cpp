#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int canMake(vector<int> &bloomDay, int mid, int k)
    {
        int count = 0;
        int consec_Count = 0;

        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                consec_Count++;
            }
            else
            {
                consec_Count = 0;
            }

            if (consec_Count == k)
            {
                count++; // bouque count
                consec_Count = 0;
            }
        }

        return count;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int start = 0;
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int mid = start + (end - start) / 2;
        int minDays = -1;

        while (start <= end)
        {
            if (canMake(bloomDay, mid, k) >= m)
            {
                minDays = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }

        return minDays;
    }
};
