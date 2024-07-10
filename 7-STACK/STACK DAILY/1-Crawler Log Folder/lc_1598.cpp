#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<string> st;

        for (auto &str : logs)
        {
            if (str == "../")
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else if (str == "./")
            {
            }
            else
            {
                st.push(str);
            }
        }

        return st.size();
    }
};