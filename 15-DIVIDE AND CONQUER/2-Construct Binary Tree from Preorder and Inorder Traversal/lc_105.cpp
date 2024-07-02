// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode *Solve(vector<int> &preorder, vector<int> &inorder, int start, int end, int &idx)
    {
        if (start > end)
        {
            return NULL;
        }

        int i = start;
        for (; i <= end; i++)
        {
            if (inorder[i] == preorder[idx])
            {
                break;
            }
        }
        idx++;

        TreeNode *root = new TreeNode(inorder[i]);

        root->left = Solve(preorder, inorder, start, i - 1, idx);
        root->right = Solve(preorder, inorder, i + 1, end, idx);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int idx = 0;

        return Solve(preorder, inorder, 0, preorder.size() - 1, idx);
    }
};
