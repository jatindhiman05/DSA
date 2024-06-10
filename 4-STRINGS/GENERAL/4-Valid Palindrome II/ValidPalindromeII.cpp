#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkPalidrome(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                bool remove_i = checkPalidrome(s, i + 1, j);
                bool remove_j = checkPalidrome(s, i, j - 1);

                return remove_i || remove_j;
            }
        }

        return true;
    }
};