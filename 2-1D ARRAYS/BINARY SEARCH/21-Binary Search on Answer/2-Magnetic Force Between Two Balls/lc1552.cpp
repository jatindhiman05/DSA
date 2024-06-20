#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool possibleToPlace(int mid, vector<int> &position, int m)
    {
        int prev = position[0];
        int k = 1;

        for (int i = 1; i < position.size(); i++)
        {
            int curr = position[i];

            if (curr - prev >= mid)
            {
                k++;
                prev = curr;
            }

            if (k == m)
            {
                break;
            }
        }

        return k == m;
    }

    int maxDistance(vector<int> &position, int m)
    {
        int n = position.size();
        sort(position.begin(), position.end());

        int start = 1;
        int end = position[n - 1] - position[0];
        int mid = start + (end - start) / 2;

        int result = 0;
        while (start <= end)
        {
            if (possibleToPlace(mid, position, m))
            {
                result = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }

        return result;
    }
};