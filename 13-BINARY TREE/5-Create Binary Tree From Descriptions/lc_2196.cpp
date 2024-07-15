#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> map;
        unordered_set<int> childs;

        for (auto &desc : descriptions)
        {
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            if (map.find(parent) == map.end())
            {
                map[parent] = new TreeNode(parent);
            }

            if (map.find(child) == map.end())
            {
                map[child] = new TreeNode(child);
            }

            if (isLeft == 1)
            {
                map[parent]->left = map[child];
            }
            else
            {
                map[parent]->right = map[child];
            }

            childs.insert(child);
        }

        for (auto &i : descriptions)
        {
            int parent = i[0];
            if (childs.find(parent) == childs.end())
            {
                return map[parent];
            }
        }

        return NULL;
    }
};