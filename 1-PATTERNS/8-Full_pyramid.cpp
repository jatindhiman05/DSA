#include <iostream>
using namespace std;

void fullPyramid()
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5 - row - 1; col++)
        {
            cout << " ";
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
    fullPyramid();

    return 0;
}