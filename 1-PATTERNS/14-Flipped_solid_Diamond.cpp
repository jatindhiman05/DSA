#include <iostream>
using namespace std;

void Flipped_solid_diamond(int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n - row; col++)
        {
            cout << "* ";
        }
        for (int col = 0; col < ((2 * row) + 1); col++)
        {
            cout << "  ";
        }
        for (int col = 0; col < n - row; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }
        for (int col = 0; col < ((2 * n) - 1 - (2 * row)); col++)
        {
            cout << "  ";
        }
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter n ";
    cin >> n;
    Flipped_solid_diamond(n / 2);

    return 0;
}