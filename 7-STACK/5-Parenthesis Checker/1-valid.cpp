// https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;

        for (int i = 0; i < x.length(); i++)
        {
            char ch = x[i];
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                char top = st.top();
                if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};