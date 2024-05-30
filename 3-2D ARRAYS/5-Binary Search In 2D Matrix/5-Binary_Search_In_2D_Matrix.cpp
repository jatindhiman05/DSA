#include <iostream>
#include <vector>
using namespace std;

// Approach - 1

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n - 1;

        while (i < m && j >= 0)
        {
            if (matrix[i][j] > target)
            {
                j--;
            }
            else if (matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};

// Approach - 2

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // Mapping 2d <-> 1d
        int m = matrix.size();
        int n = matrix[0].size();

        int start = 0;
        int end = m * n - 1;

        int mid = start + (end - start) / 2;
        while (start <= end)
        {
            if (matrix[mid / n][mid % n] > target)
            { // !!!!!
                end = mid - 1;
            }
            else if (matrix[mid / n][mid % n] < target)
            {
                start = mid + 1;
            }
            else
            {
                return true;
            }
            mid = start + (end - start) / 2;
        }

        return false;
    }
};