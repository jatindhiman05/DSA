// https://leetcode.com/problems/custom-sort-string/description/
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        sort(s.begin(), s.end(), [order](char a, char b)
             { return order.find(a) < order.find(b); });

        return s;
    }
};