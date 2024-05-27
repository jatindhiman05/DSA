#include <iostream>
using namespace std;

void butterfly_pattern(int n)
{
    int n_ = n / 2;

    for (int row = 0; row < n_; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }

        for (int col = 0; col < 2 * n_ - 2 * row - 2; col++)
        {
            cout << "  ";
        }
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int row = 0; row < n_; row++)
    {
        for (int col = 0; col < n_ - row; col++)
        {
            cout << "* ";
        }

        for (int col = 0; col < 2 * row; col++)
        {
            cout << "  ";
        }
        for (int col = 0; col < n_ - row; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    butterfly_pattern(8);

    return 0;
}