// https://leetcode.com/problems/satisfiability-of-equality-equations/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<int> parent;
    vector<int> rank;

public:
    int find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
        {
            return;
        }

        if (rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    bool equationsPossible(vector<string> &equations)
    {
        parent.resize(26);
        rank.resize(26, 0);

        for (int i = 0; i < 26; i++)
        {
            parent[i] = i;
        }

        for (auto &s : equations)
        {
            char first = s[0];
            char second = s[3];

            if (s[1] == '=')
            {
                Union(first - 'a', second - 'a');
            }
        }

        for (auto &s : equations)
        {
            char first = s[0];
            char second = s[3];

            if (s[1] == '!')
            {
                int first_parent = find(first - 'a');
                int second_parent = find(second - 'a');

                if (first_parent == second_parent)
                {
                    return false;
                }
            }
        }

        return true;
    }
};