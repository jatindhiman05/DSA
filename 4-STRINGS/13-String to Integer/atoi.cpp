// https://leetcode.com/problems/string-to-integer-atoi/description/
#include <iostream>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int num = 0;
        int i = 0;
        int sign = 1; // by default +ve

        // ignore whitespace
        while (s[i] == ' ')
        {
            i++;
        }

        // check sign char if present
        if (i < s.length() && (s[i] == '+' || s[i] == '-'))
        {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }

        // read num character if isDigit
        while (i < s.length() && isdigit(s[i]))
        {
            // out of bound
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7'))
            { // intmax - > 2147483647
                return sign == -1 ? INT_MIN : INT_MAX;
            }

            num = num * 10 + (s[i] - '0');
            i++;
        }

        return num * sign;
    }
};