// https://leetcode.com/problems/clone-graph/
// do bfs
#include <iostream>
#include <vector>
using namespace std;

// DFS
class Solution
{
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &board, vector<pair<int, int>> &directions)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O' || visited[i][j])
        {
            return;
        }

        visited[i][j] = 1;

        for (auto &dir : directions)
        {
            int i_ = i + dir.first;
            int j_ = j + dir.second;

            dfs(i_, j_, visited, board, directions);
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O' && !visited[0][j])
            {
                dfs(0, j, visited, board, directions);
            }

            if (board[m - 1][j] == 'O' && !visited[m - 1][j])
            {
                dfs(m - 1, j, visited, board, directions);
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O' && !visited[i][0])
            {
                dfs(i, 0, visited, board, directions);
            }

            if (board[i][n - 1] == 'O' && !visited[i][n - 1])
            {
                dfs(i, n - 1, visited, board, directions);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && !visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};