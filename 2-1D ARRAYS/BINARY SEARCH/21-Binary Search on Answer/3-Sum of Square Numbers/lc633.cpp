#include <iostream>
using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long long start = 0;
        long long end = sqrt(c);

        while (start <= end)
        {
            long long sumOFSquare = (start * start + end * end);
            if (sumOFSquare == c)
            {
                return true;
            }
            else if (sumOFSquare > c)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        return false;
    }
};