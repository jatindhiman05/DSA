#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string result;

        for (char &ch : s)
        {
            result.push_back(ch);

            if (result.size() >= part.size() && result.substr(result.size() - part.size()) == part)
            {
                result.erase(result.size() - part.size());
            }
        }

        return result;
    }
};