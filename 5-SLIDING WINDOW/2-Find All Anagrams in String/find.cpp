// https://leetcode.com/problems/find-all-anagrams-in-a-string/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool allZeroes(vector<int> &freq)
    {
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> freq(26, 0);
        vector<int> result;
        for (int i = 0; i < p.length(); i++)
        {
            freq[p[i] - 'a']++;
        }

        int i = 0, j = 0;

        while (j < s.length())
        {
            freq[s[j] - 'a']--;

            if (j - i + 1 == p.length())
            {
                if (allZeroes(freq))
                {
                    result.push_back(i);
                }

                freq[s[i] - 'a']++; // i out of wind
                i++;
            }

            j++;
        }

        return result;
    }
};