#include <iostream>
using namespace std;

void halfPyramid()
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    halfPyramid();

    return 0;
}