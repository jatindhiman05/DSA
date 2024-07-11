#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

// Approach-2 (Brute Force)
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<pair<char, int>> st;
        string result = "";

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '(')
            {
                st.push({ch, i});
            }
            else if (ch == ')')
            {
                if (st.top().first == '(')
                {
                    reverse(s.begin() + st.top().second, s.begin() + i);
                    st.pop();
                }
            }
        }

        for (auto &ch : s)
        {
            if (ch != ')' && ch != '(')
            {
                result += ch;
            }
        }

        return result;
    }
};

// Approach-2 (Linear Approach)
class Solution
{
public:
    string reverseParentheses(string s)
    {
        int n = s.length();
        stack<int> openBracket;
        vector<int> door(n);

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                openBracket.push(i);
            }
            else if (s[i] == ')')
            {
                int j = openBracket.top();
                openBracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        string result;
        int direction = 1;
        for (int i = 0; i < n; i += direction)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                i = door[i];
                direction = -direction;
            }
            else
            {
                result += s[i];
            }
        }
        return result;
    }
};