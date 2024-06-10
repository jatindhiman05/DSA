// https://leetcode.com/problems/string-compression/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int idx = 0;
        int count = 1;

        int prev = 0;
        int curr = 1;

        while (curr < chars.size())
        {
            if (chars[curr] == chars[prev])
            {
                count++;
            }
            else
            {
                chars[idx++] = chars[prev];
                if (count > 1)
                {
                    int s = idx;
                    while (count)
                    {
                        // each count char at new idx
                        chars[idx++] = (count % 10) + '0';
                        count /= 10;
                    }
                    // count got printed in reverse -> revert
                    reverse(chars.begin() + s, chars.begin() + idx);
                }
                prev = curr;
                count = 1;
            }
            curr++;
        }

        // curr goes out of bound print last chars
        chars[idx++] = chars[prev];
        if (count > 1)
        {
            int s = idx;
            while (count)
            {
                chars[idx++] = (count % 10) + '0';
                count /= 10;
            }
            reverse(chars.begin() + s, chars.begin() + idx);
        }

        return idx;
    }
};