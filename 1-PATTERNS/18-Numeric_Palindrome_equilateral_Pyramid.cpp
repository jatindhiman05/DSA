#include <iostream>
using namespace std;

void Numeric_Palindrome_equilateral_Pyramid(int n)
{
    for (int row = 0; row < n; row++)
    {
        int k;
        for (int col = 0; col < row + 1; col++)
        {
            k = col + 1;
            cout << k << " ";
        }
        for (int i = k - 1; i > 0; i--)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    Numeric_Palindrome_equilateral_Pyramid(10);

    return 0;
}