#include <iostream>
#include <vector>
using namespace std;

// TC: O(n^2)
int maximumProduct(vector<int> &arr, int n)
{
    int maxi = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        int product = 1;
        for (int j = i; j < arr.size(); j++)
        {
            product *= arr[j];
            maxi = max(maxi, product);
        }
    }

    return maxi;
}

// TC: O(n)
int maximumProduct(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    int prefix = 1;
    int suffix = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (prefix == 0)
        {
            prefix = 1;
        }

        if (suffix == 0)
        {
            suffix = 1;
        }

        prefix *= arr[i];
        suffix *= arr[n - i - 1];

        maxi = max(maxi, max(prefix, suffix));
    }

    return maxi;
}
