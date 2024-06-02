#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        map<int, vector<int>> map;

        vector<int> result;

        // populate map
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                map[i + j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for (auto &it : map)
        {
            if (flip)
            {
                reverse(it.second.begin(), it.second.end());
            }

            for (int &num : it.second)
            {
                result.push_back(num);
            }

            flip = !flip;
        }

        return result;
    }
};