#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int ans = 0;
        stack<int> st;
        if (x > y)
        {
            for (auto &ch : s)
            {
                if (!st.empty() && st.top() == 'a' && ch == 'b')
                {
                    ans += x;
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
            string temp = "";

            while (!st.empty())
            {
                temp += st.top();
                st.pop();
            }

            reverse(temp.begin(), temp.end());

            for (auto &ch : temp)
            {
                if (!st.empty() && st.top() == 'b' && ch == 'a')
                {
                    ans += y;
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }
        else
        {
            for (auto &ch : s)
            {
                if (!st.empty() && st.top() == 'b' && ch == 'a')
                {
                    ans += y;
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
            string temp = "";

            while (!st.empty())
            {
                temp += st.top();
                st.pop();
            }

            reverse(temp.begin(), temp.end());

            for (auto &ch : temp)
            {
                if (!st.empty() && st.top() == 'a' && ch == 'b')
                {
                    ans += x;
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }

        return ans;
    }
};