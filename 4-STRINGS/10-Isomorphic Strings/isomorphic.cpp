// https://leetcode.com/problems/isomorphic-strings/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, char> map_st;
        unordered_map<char, char> map_ts;

        for (int i = 0; i < t.length(); i++)
        {
            if (map_st.find(s[i]) != map_st.end() && map_st[s[i]] != t[i])
            {
                return false;
            }
            map_st[s[i]] = t[i];

            if (map_ts.find(t[i]) != map_st.end() && map_ts[t[i]] != s[i])
            {
                return false;
            }
            map_ts[t[i]] = s[i];
        }

        return true;
    }
};