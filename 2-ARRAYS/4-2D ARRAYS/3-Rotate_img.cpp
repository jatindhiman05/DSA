// very very imp
// Rotate image https://leetcode.com/problems/rotate-image/ LC->48

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // take transpose
        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = row; col < matrix.size(); col++)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // reverse

        for (int row = 0; row < matrix.size(); row++)
        {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};