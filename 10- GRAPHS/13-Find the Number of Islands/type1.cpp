// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j, vector<pair<int, int>> &dir)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
            return;

        grid[i][j] = '$';

        for (pair<int, int> &p : dir)
        {
            int new_i = i + p.first;
            int new_j = j + p.second;
            dfs(grid, new_i, new_j, dir);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        // Directions for all 8 possible moves (horizontal, vertical, and diagonal)
        vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, dir);
                    count++;
                }
            }
        }

        return count;
    }
};