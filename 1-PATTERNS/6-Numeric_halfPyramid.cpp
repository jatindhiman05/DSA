#include <iostream>
using namespace std;

void numric_halfPyramid()
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << col + 1 << " ";
        }
        cout << endl;
    }
}

int main()
{
    numric_halfPyramid();

    return 0;
}