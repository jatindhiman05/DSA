#include <iostream>
using namespace std;

void invertedFullPyramid()
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < row; col++)
        {
            cout << " ";
        }

        for (int col = 0; col < 4 - row; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}

int main()
{
    invertedFullPyramid();

    return 0;
}