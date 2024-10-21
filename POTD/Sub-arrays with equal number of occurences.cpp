#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int sameOccurrence(vector<int> &arr, int x, int y)
    {
        unordered_map<int, int> value;

        int countX = 0, countY = 0;
        int ans = 0;
        value[0] = 1;

        for (auto ele : arr)
        {
            if (ele == x)
                countX++;
            if (ele == y)
                countY++;

            int diff = countX - countY;

            ans += (value[diff]);
            value[diff]++;
        }

        return ans;
    }
};