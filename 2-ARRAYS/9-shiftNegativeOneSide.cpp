#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shiftNegativeOneSide(int arr[], int size)
{
    int l = 0;
    int h = size - 1;

    while (l < h)
    {
        if (arr[l] < 0)
        {
            l++;
        }
        else if (arr[h] > 0)
        {
            h--;
        }
        else
        {
            swap(arr[l], arr[h]);
        }
    }
}

int main()
{
    int arr[] = {2, 4, -6,18, -1, -3, -7, 9, 11, -45};
    int size = 9;

    printArray(arr, size);
    shiftNegativeOneSide(arr, size);
    printArray(arr, size);
    return 0;
}