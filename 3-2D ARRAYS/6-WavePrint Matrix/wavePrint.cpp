#include <iostream>
#include <vector>
using namespace std;

void wavePrint(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    int top = 0;
    int down = m - 1;
    int right = n - 1;
    int left = 0;
    bool flip = true;
    while (top <= down && left <= right)
    {
        if (flip)
        {
            for (int i = top; i <= down; i++)
            {
                cout << mat[i][left] << " ";
            }
        }
        else
        {
            for (int i = down; i >= top; i--)
            {
                cout << mat[i][left] << " ";
            }
        }
        left++;
        flip = !flip;
    }
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12}};

    wavePrint(mat);
    return 0;
}