// https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> leftSmaller(int n, int a[])
    {
        vector<int> result(n);
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            int curr = a[i];

            while (st.top() >= curr)
            {
                st.pop();
            }

            result[i] = st.top();

            st.push(curr);
        }

        return result;
    }
};