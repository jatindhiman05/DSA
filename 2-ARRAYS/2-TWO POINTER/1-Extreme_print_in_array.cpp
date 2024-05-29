#include <iostream>
using namespace std;

void extremePrintArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        if (start == end)
        {
            cout << arr[start++] << " ";
        }
        else
        {
            cout << arr[start++] << " ";
            cout << arr[end--] << " ";
        }
    }
}

int main()
{
    int arr[] = {2, 4, 6, 1, 3, 7, 9, 12, 56, 43, 21};
    int size = 11;

    extremePrintArray(arr, size);
    return 0;
}