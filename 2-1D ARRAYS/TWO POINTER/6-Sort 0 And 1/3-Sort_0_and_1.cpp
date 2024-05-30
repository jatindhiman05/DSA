// https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

#include <iostream>
using namespace std;

class solution
{
    void segregate0and1(int arr[], int n)
    {
        int l = 0;
        int h = n - 1;

        while (l < h)
        {
            if (arr[l] == 0)
            {
                l++;
            }
            else if (arr[h] == 1)
            {
                h--;
            }
            else
            {
                swap(arr[l], arr[h]);
            }
        }
    }
};
