// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            char ch = s[i];
            if (st.empty() || st.top() != ch)
                st.push(ch);
            else
                st.pop();
        }

        string result = "";
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }
};