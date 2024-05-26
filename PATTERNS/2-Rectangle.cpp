#include <iostream>
using namespace std;

void rectangle()
{

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    rectangle();

    return 0;
}