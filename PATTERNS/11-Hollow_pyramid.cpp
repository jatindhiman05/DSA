#include <iostream>
using namespace std;

void hollow_pyramid()
{
    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 20 - row - 1; col++)
        {
            cout << " ";
        }

        for (int col = 0; col < row + 1; col++)
        {
            if (col == 0 || col == row)
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
    hollow_pyramid();
    return 0;
}