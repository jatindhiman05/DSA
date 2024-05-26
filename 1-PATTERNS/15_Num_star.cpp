#include <iostream>
using namespace std;

void num_star(int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < (2 * row) + 1; col++)
        {
            if ((col % 2) == 0)
            {
                cout << row + 1 << " ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

int main()
{
    num_star(10);

    return 0;
}