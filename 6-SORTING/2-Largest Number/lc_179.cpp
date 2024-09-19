#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> nums_;
        for (auto &num : nums)
        {
            nums_.push_back(to_string(num));
        }

        sort(nums_.begin(), nums_.end(), [](string &s1, string &s2)
             { return s1 + s2 > s2 + s1; });

        string result = "";

        for (auto &str : nums_)
        {
            result += str;
        }
        int i = 0;

        while (i < result.length() && result[i] == '0')
        {
            i++;
        }

        if (result.substr(i) == "")
        {
            return "0";
        }

        return result.substr(i);
    }
};