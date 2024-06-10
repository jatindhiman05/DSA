// https://leetcode.com/problems/replace-words/
#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
    string findRoot(string &word, unordered_set<string> &st)
    {
        for (int i = 1; i < word.length(); i++)
        {
            string root = word.substr(0, i);
            if (st.find(root) != st.end())
            {
                return root;
            }
        }

        return word;
    }
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string word;
        string result;

        while (getline(ss, word, ' '))
        { // tokenize wrt ' '
            result += findRoot(word, st) + " ";
        }

        result.pop_back();

        return result;
    }
};