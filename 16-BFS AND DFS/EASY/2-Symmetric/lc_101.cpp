#include <iostream>
#include <queue>
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

// Using DFS
class Solution
{
    bool mirror(TreeNode *l, TreeNode *r)
    {
        if (!l && !r)
        {
            return true;
        }

        if (!l || !r)
        {
            return false;
        }

        if (l->val == r->val && mirror(l->left, r->right) && mirror(l->right, r->left))
        {
            return true;
        }

        return false;
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        return mirror(root->left, root->right);
    }
};