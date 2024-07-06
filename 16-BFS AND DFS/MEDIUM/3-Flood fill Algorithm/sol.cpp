// https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &image, int i, int j, int newColor, vector<vector<int>> &ans, vector<pair<int, int>> &directions, int iniColor)
    {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != iniColor || ans[i][j] == newColor)
        {
            return;
        }

        ans[i][j] = newColor;

        for (auto &dir : directions)
        {
            int i_ = i + dir.first;
            int j_ = j + dir.second;

            dfs(image, i_, j_, newColor, ans, directions, iniColor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        vector<vector<int>> ans = image;

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int iniColor = image[sr][sc];

        dfs(image, sr, sc, newColor, ans, directions, iniColor);

        return ans;
    }
};