// https://leetcode.com/problems/row-with-maximum-ones/ Row with max ones lc -> 2643
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int idx = 0;
        int countOnes = 0;

        for (int row = 0; row < mat.size(); row++)
        {
            int tempCount = 0;
            for (int col = 0; col < mat[row].size(); col++)
            {
                if (mat[row][col] == 1)
                {
                    tempCount++;
                    if (tempCount > countOnes)
                    {
                        countOnes = tempCount;
                        idx = row;
                    }
                }
            }
        }

        return {idx, countOnes};
    }
};