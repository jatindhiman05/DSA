#include <iostream>
using namespace std;

void inverted_hollow_halfPyramid(int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n - row; col++)
        {
            if (row == 0 || row == n - 1)
            {
                cout << "* ";
            }
            else
            {
                if (col == 0 || col == n - row - 1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    inverted_hollow_halfPyramid(6);

    return 0;
}