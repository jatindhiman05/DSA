#include <iostream>
#include <vector>
using namespace std;

int firstOccur(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] > k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}
int lastOccur(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] > k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = firstOccur(arr, n, k);
    int last = lastOccur(arr, n, k);

    return {first, last};
}
int count(vector<int> &arr, int n, int x)
{
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1)
    {
        return 0;
    }
    return ans.second - ans.first + 1;
}
