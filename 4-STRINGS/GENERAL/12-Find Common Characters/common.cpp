// https://leetcode.com/problems/find-common-characters/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> result;
        vector<int> count(26, 0);

        for (char &ch : words[0])
        {
            count[ch - 'a']++;
        }

        for (int i = 1; i < words.size(); i++)
        {
            vector<int> temp(26, 0);
            for (char &ch : words[i])
                temp[ch - 'a']++;
            // update count
            for (int i = 0; i < 26; i++)
            {
                if (count[i] != temp[i])
                {
                    count[i] = min(count[i], temp[i]);
                }
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                while (count[i]--)
                {
                    result.push_back(string(1, i + 'a'));
                }
            }
        }

        return result;
    }
};