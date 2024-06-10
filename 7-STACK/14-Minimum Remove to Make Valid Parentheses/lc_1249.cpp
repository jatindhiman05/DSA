// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    // replace extra bracket with * and remove * after another traverse
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else
                {
                    s[i] = '*';
                }
            }
        }

        while (!st.empty())
        {
            s[st.top()] = '*';
            st.pop();
        }

        string ans = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '*')
            {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};