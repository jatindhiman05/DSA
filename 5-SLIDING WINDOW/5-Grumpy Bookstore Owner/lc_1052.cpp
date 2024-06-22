// https://leetcode.com/problems/grumpy-bookstore-owner/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int maxUnsatisfied = 0;
        int tempUnsatisfied = 0;

        int i = 0;
        int j = 0;

        while (j < customers.size())
        {
            // here choosing subarray of max Customers does not work instead
            // count max unsatisfied customers in a particular subarray
            tempUnsatisfied += customers[j] * grumpy[j];

            if (j - i + 1 == minutes)
            {
                maxUnsatisfied = max(maxUnsatisfied, tempUnsatisfied);
                tempUnsatisfied -= customers[i] * grumpy[i];
                i++;
            }

            j++;
        }

        int result = maxUnsatisfied;

        for (int i = 0; i < customers.size(); i++)
        {
            if (grumpy[i] == 0)
            {
                result += customers[i];
            }
        }

        return result;
    }
};