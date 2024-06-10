// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr, int n)
    {
        vector<int> result;
        int repeating = 0;
        int missing = 0;

        // Find the repeating number
        for (int num : arr)
        {
            if (arr[abs(num) - 1] < 0)
            {
                repeating = abs(num);
            }
            else
            {
                arr[abs(num) - 1] *= -1; // mark -ve
            }
        }

        // Find the missing number
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                missing = i + 1;
                break;
            }
        }

        result.push_back(repeating);
        result.push_back(missing);
        return result;
    }
};