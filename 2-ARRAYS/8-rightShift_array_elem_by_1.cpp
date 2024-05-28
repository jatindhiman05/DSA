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

void shift_array_by_one(int arr[], int size)
{
    int temp = arr[size - 1];
    for (int i = size - 1; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = temp;
}

int main()
{
    int arr[] = {2, 4, 6, 1, 3, 7, 9};
    int size = 7;

    printArray(arr, size);
    shift_array_by_one(arr, size);
    printArray(arr, size);

    return 0;
}