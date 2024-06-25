#include <iostream>
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
public:
    void inOrder(TreeNode *root, vector<TreeNode *> &nodes)
    {
        if (!root)
            return;

        inOrder(root->left, nodes);
        nodes.push_back(root);
        inOrder(root->right, nodes);
    }

    TreeNode *bstToGst(TreeNode *root)
    {
        vector<TreeNode *> nodes;
        inOrder(root, nodes);

        int sum = 0;
        for (int i = nodes.size() - 1; i >= 0; i--)
        {
            sum += nodes[i]->val;
            nodes[i]->val = sum;
        }

        return root;
    }
};