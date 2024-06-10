// https://leetcode.com/problems/decode-the-message/description/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        string decodedMessage = "";
        unordered_map<char, char> map;
        char ch = 'a';

        for (char &c : key)
        {
            if (c != ' ' && map.find(c) == map.end())
            {
                map[c] = ch;
                ch++;
            }
        }

        for (char &c : message)
        {
            if (c == ' ')
            {
                decodedMessage += ' ';
            }
            else
            {
                decodedMessage += map[c];
            }
        }
        // cout<<decodedMessage;
        return decodedMessage;
    }
};