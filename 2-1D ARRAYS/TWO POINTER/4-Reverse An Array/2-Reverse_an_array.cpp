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

void reverse(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        swap(arr[start++], arr[end--]);
    }
}

int main()
{
    int arr[] = {2, 4, 6, 1, 3, 7, 9, 12, 56, 43, 21};
    int size = 11;

    printArray(arr, size);
    reverse(arr, size);
    printArray(arr, size);
    return 0;
}