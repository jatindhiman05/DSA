// https://leetcode.com/problems/group-anagrams/
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;

        for (auto &str : strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            map[s].push_back(str);
        }

        for (auto &pair : map)
        {
            result.push_back(pair.second);
        }

        return result;
    }
};