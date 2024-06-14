// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
#include <iostream>
#include<stack>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int maxDepth = 0;
        stack<int> st;

        for (char &ch : s)
        {
            if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                st.pop();
            }

            maxDepth = max(maxDepth, (int)st.size()); // st.size() => size_t type
        }

        return maxDepth;
    }
};