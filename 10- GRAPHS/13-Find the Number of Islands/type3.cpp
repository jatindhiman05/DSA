#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void DFS(vector<vector<int>> &grid, int row, int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
        {
            return;
        }

        if (grid[row][col] == 0)
        {
            return;
        }

        grid[row][col] = 0;

        for (auto &dir : directions)
        {
            int i_ = row + dir.first;
            int j_ = col + dir.second;

            DFS(grid, i_, j_);
        }
    }
    int noOFIslands(vector<vector<int>> grid)
    {
        int islands = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    DFS(grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }

public:
    int minDays(vector<vector<int>> &grid)
    {
        int islands = noOFIslands(grid);
        if (islands == 0 || islands > 1)
        {
            return 0;
        }
        else
        {
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[0].size(); j++)
                {
                    if (grid[i][j] == 1)
                    {
                        grid[i][j] = 0;

                        islands = noOFIslands(grid);

                        if (islands == 0 || islands > 1)
                        {
                            return 1;
                        }

                        grid[i][j] = 1;
                    }
                }
            }
        }

        return 2;
    }
};