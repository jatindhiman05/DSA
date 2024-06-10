// https://leetcode.com/problems/remove-k-digits/
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<int> st;
        string result;
        for (char ch : num)
        {
            while (!st.empty() && k > 0 && ch < st.top())
            {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while (k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }

        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        int i = 0;
        while (i < result.size() && result[i] == '0')
        {
            i++;
        }
        result.erase(0, i);
        if (result.empty())
        {
            return "0";
        }
        else
        {
            return result;
        }
    }
};