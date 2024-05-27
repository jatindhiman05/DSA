#include <iostream>
#include <string>
using namespace std;

void charPattern(int n)
{
    char ch;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            ch = col + 1 + 'A' - 1;
            cout << ch<<" ";
        }
        for (char i = ch; i > 'A';)
        {
            i = i - 1;
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    charPattern(5);

    return 0;
}