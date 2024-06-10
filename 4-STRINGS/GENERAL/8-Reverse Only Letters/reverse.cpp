// https://leetcode.com/problems/reverse-only-letters/
#include <iostream>
using namespace std;

class Solution
{
public:
    bool validChar(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            return true;
        }

        return false;
    }
    string reverseOnlyLetters(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i < j)
        {
            if (!validChar(s[i]))
            {
                i++;
            }
            else if (!validChar(s[j]))
            {
                j--;
            }
            else
            {
                swap(s[i++], s[j--]);
            }
        }

        return s;
    }
};