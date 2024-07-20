#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        vector<vector<int>> result(rowSum.size(), vector<int>(colSum.size()));

        int i = 0;
        int j = 0;

        while (i < rowSum.size() && j < colSum.size())
        {
            result[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= result[i][j];
            colSum[j] -= result[i][j];

            if (rowSum[i] == 0)
            {
                i++;
            }

            if (colSum[j] == 0)
            {
                j++;
            }
        }

        return result;
    }
};