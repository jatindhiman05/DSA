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
    vector<int> nodes;

public:
    void inOrder(TreeNode *root)
    {
        if (!root)
            return;

        inOrder(root->left);
        nodes.push_back(root->val);
        inOrder(root->right);
    }

    TreeNode *make_balanced(int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;

        TreeNode *newRoot = new TreeNode(nodes[mid]);
        newRoot->left = make_balanced(start, mid - 1);
        newRoot->right = make_balanced(mid + 1, end);

        return newRoot;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        inOrder(root);

        return make_balanced(0, nodes.size() - 1);
    }
};