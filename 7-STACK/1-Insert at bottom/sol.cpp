// https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1
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
    stack<int> insertAtBottom(stack<int> st, int x)
    {
        insertAtBottom_helper(st, x);

        return st;
    }
};