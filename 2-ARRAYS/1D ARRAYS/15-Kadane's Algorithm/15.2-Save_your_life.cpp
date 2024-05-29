#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;

// kadane variation
class Solution
{
public:
    string maxSum(string w, char x[], int b[], int n)
    {
        unordered_map<char, int> map;

        for (int i = 0; i < n; i++)
        {
            map[x[i]] = b[i];
        }

        int maxSum = INT_MIN;
        int currSum = 0;

        string ans = "";
        string temp = "";

        for (int i = 0; i < w.length(); i++)
        {
            int ascii;
            if (map.find(w[i]) != map.end())
            {
                ascii = map[w[i]];
            }
            else
            {
                ascii = (int)w[i];
            }

            currSum += ascii;
            temp += w[i];

            if (currSum > maxSum)
            {
                maxSum = currSum;
                ans = temp;
            }

            if (currSum < 0)
            {
                currSum = 0;
                temp = "";
            }
        }

        return ans;
    }
};