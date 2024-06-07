// https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
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
    int search(string pat, string txt)
    {
        int result = 0;

        vector<int> freq(26, 0);

        for (int i = 0; i < pat.length(); i++)
        {
            freq[pat[i] - 'a']++;
        }

        int i = 0, j = 0;

        while (j < txt.length())
        {
            freq[txt[j] - 'a']--;

            // window size == pat length ?
            if (j - i + 1 == pat.length())
            {
                if (allZeroes(freq))
                {
                    result++;
                }

                // i out of window inc freq
                freq[txt[i] - 'a']++;
                i++;
            }

            j++;
        }

        return result;
    }
};