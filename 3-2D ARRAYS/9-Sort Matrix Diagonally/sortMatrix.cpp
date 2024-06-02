#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, vector<int>> map;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                map[i - j].push_back(mat[i][j]);
            }
        }

        for (auto &it : map)
        {
            sort(it.second.begin(), it.second.end());
        }

        // put them back

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                mat[i][j] = map[i - j].back();
                map[i - j].pop_back();
            }
        }

        return mat;
    }
};