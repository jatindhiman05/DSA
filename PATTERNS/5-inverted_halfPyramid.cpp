#include <iostream>
using namespace std;

void inverted_halfPyramnid()
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5 - row; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    inverted_halfPyramnid();

    return 0;
}