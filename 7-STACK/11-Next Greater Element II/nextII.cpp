// https://leetcode.com/problems/next-greater-element-ii/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> result(n);

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int num = nums[i % n]; // circular search

            while (!st.empty() && st.top() <= num)
            {
                st.pop();
            }

            result[i % n] = st.empty() ? -1 : st.top();

            st.push(num);
        }

        return result;
    }
};