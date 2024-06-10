// https://leetcode.com/problems/min-stack/
#include <iostream>
#include <vector>
using namespace std;

class MinStack
{
    vector<pair<int, int>> st; // {val,min}
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push_back({val, val});
        }
        else
        {
            st.back().second < val ? st.push_back({val, st.back().second}) : st.push_back({val, val});
        }
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        return st.back().first;
    }

    int getMin()
    {
        return st.back().second;
    }
};