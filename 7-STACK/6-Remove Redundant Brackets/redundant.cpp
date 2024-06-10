// https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int checkRedundancy(string s)
    {
        stack<char> st;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
                st.push(ch);
            else if (ch == ')')
            {
                int operatorCount = 0;
                while (st.size() != 0 && st.top() != '(')
                {
                    char temp = st.top();
                    if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                        operatorCount++;
                    st.pop();
                }
                st.pop();
                if (operatorCount == 0)
                    return 1;
            }
        }

        return 0;
    }
};