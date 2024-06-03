// https://leetcode.com/problems/valid-anagram/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> freq(26, 0);

        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); i++)
        {
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};