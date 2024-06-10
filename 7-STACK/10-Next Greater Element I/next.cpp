// https://leetcode.com/problems/next-greater-element-i/description/
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        vector<int> result(nums1.size());
        unordered_map<int, int> map; // to store next greater

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            int num = nums2[i];

            while (!st.empty() && st.top() <= num)
            {
                st.pop();
            }

            map[num] = st.empty() ? -1 : st.top();

            st.push(num);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            result[i] = map[nums1[i]];
        }

        return result;
    }
};