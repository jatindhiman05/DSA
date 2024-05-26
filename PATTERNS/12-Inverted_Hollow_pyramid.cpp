#include <iostream>
using namespace std;

void inverted_hollow_pyramid(int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row; col++)
        {
            cout << " ";
        }

        for (int col = 0; col < n - row; col++)
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

        cout << endl;
    }
}

int main()
{
    inverted_hollow_pyramid(10);

    return 0;
}