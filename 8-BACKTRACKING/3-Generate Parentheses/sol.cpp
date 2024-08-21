#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    bool isValid(string s)
    {
        stack<int> st;

        for (auto &ch : s)
        {
            if (ch == '(')
            {
                st.push(ch);
            }
            else
            {
                if (!st.empty() && st.top() == '(')
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
    vector<string> result;
    void solve(string &curr, int n)
    {
        if (curr.length() == 2 * n)
        {
            if (isValid(curr))
            {
                result.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();
    }

public:
    vector<string> generateParenthesis(int n)
    {
        string curr = "";

        solve(curr, n);

        return result;
    }
};