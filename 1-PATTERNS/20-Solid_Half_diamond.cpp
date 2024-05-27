#include <iostream>
using namespace std;

void Solid_Half_diamond(int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }
    for (int row = 1; row < n; row++)
    {
        for (int col = 0; col < n - row; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}

int main()
{
    Solid_Half_diamond(6);

    return 0;
}