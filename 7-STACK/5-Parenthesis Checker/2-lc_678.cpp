// https://leetcode.com/problems/valid-parenthesis-string/
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> st1;
        stack<int> st2;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (ch == '(')
            {
                st1.push(i);
            }
            else if (ch == ')')
            {
                if (!st1.empty())
                {
                    st1.pop();
                }
                else if (!st2.empty())
                {
                    st2.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (ch == '*')
            {
                st2.push(i);
            }
        }

        while (!st1.empty() && !st2.empty())
        {
            int top = st2.top();
            st2.pop();
            if (st1.top() < top)
            {
                st1.pop();
            }
        }

        return st1.empty();
    }
};