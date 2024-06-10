// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        stack<int> st;
        st.push(-1);

        // discount[i] is the next smaller elem
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            int price = prices[i];

            while (st.top() > price)
                st.pop();

            if (st.top() != -1)
                prices[i] -= st.top();

            st.push(price);
        }

        return prices;
    }
};