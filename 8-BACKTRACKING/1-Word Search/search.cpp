// https://leetcode.com/problems/word-search/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool DFS(vector<vector<char>> &board, int i, int j, int idx, string &word)
    {
        if (idx == word.length())
        {
            return true;
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '$')
        {
            return false;
        }

        if (board[i][j] != word[idx])
        {
            return false;
        }

        char temp = board[i][j]; // store

        board[i][j] = '$'; // mark

        for (auto &dir : directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (DFS(board, i_, j_, idx + 1, word))
                return true;
        }

        // backtrack
        board[i][j] = temp;

        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0] && DFS(board, i, j, 0, word))
                {
                    return true;
                }
            }
        }

        return false;
    }
};