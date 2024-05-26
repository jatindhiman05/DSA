#include <iostream>
using namespace std;

void InvertedNumeric_halfPyramid()
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5 - row; col++)
        {
            cout << col + 1 << " ";
        }

        cout << endl;
    }
}

int main()
{
    InvertedNumeric_halfPyramid();

    return 0;
}