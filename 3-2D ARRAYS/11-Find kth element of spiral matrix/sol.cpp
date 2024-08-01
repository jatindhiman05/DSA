#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    /*You are required to complete this method*/
    int findK(vector<vector<int>> &arr, int n, int m, int k)
    {

        int l = 0;
        int r = m - 1;
        int up = 0;
        int down = n - 1;

        while (l <= r && up <= down)
        {
            // Calculate the number of elements in the current layer of the spiral
            int a = r - l + 1;
            int b = down - up;
            int c = r - l;
            int d = down - up - 1;

            if (k <= a)
            {
                return arr[up][l + k - 1];
            }
            k -= a;

            if (k <= b)
            {
                return arr[up + k][r];
            }
            k -= b;

            if (k <= c)
            {
                return arr[down][r - k];
            }
            k -= c;

            if (k <= d)
            {
                return arr[down - k][l];
            }
            k -= d;

            // Move to the next layer of the spiral
            l++;
            r--;
            up++;
            down--;
        }
    }
};