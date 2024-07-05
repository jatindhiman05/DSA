// https://leetcode.com/problems/minimum-distance-between-bst-nodes/
#include <iostream>
#include <queue>
#include <vector>
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
    void inorder(TreeNode *root, int &prev, int &mini)
    {
        if (!root)
            return;

        inorder(root->left, prev, mini);

        if (prev != -1)
        {
            mini = min(mini, root->val - prev);
        }

        prev = root->val;

        inorder(root->right, prev, mini);
    }

public:
    int minDiffInBST(TreeNode *root)
    {
        int prev = -1;
        int mini = INT_MAX;

        inorder(root, prev, mini);

        return mini;
    }
};