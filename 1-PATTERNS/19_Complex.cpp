#include <iostream>
using namespace std;

void complex(int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < (2 * n - row - 2); col++)
        {
            cout << "* ";
        }

        for (int col = 0; col < (2 * row) + 1; col++)
        {
            if ((col % 2) == 0)
            {
                cout << row + 1 << " ";
            }
            else
            {
                cout << "* ";
            }
        }
        for (int col = 0; col < (2 * n - row - 2); col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    complex(5);

    return 0;
}