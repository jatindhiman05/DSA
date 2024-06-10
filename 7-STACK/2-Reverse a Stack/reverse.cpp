// https://www.geeksforgeeks.org/problems/reverse-a-stack/1
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void insertAtBottom_helper(stack<int> &st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }

        int top = st.top();
        st.pop();

        insertAtBottom_helper(st, x);

        st.push(top);
    }
    void Reverse(stack<int> &St)
    {
        if (St.empty())
        {
            return;
        }

        int top = St.top();
        St.pop();

        Reverse(St);

        insertAtBottom_helper(St, top);
    }
};