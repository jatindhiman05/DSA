#include <iostream>
using namespace std;

void squarePattern()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}

int main()
{
    squarePattern();

    return 0;
}