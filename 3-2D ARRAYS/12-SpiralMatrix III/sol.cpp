#include<iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> result;
        result.push_back({rStart, cStart});

        int dir = 0;
        int gridToVisit = 1;

        while (result.size() < rows * cols)
        {
            for (int i = 0; i < gridToVisit; i++)
            {
                rStart += directions[dir].first;
                cStart += directions[dir].second;

                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                {
                    result.push_back({rStart, cStart});
                }
            }

            dir = (dir + 1) % 4;

            if (dir == 0 || dir == 2)
            {
                gridToVisit++;
            }
        }

        return result;
    }
};
