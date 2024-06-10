// https://www.geeksforgeeks.org/problems/minimum-swaps/1?
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        vector<pair<int, int>> temp;
        int swaps = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i != temp[i].second)
            {
                swaps++;
                swap(temp[i], temp[temp[i].second]);
                i--;
            }
        }

        return swaps;
    }
};
