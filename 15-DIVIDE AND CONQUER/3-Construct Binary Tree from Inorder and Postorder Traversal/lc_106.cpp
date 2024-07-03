// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode *Solve(vector<int> &inorder, vector<int> &postorder, int start, int end, int postStart, int postEnd)
    {
        if (start > end)
            return NULL;

        int i = start;

        for (; i <= end; i++)
        {
            if (inorder[i] == postorder[postEnd])
            {
                break;
            }
        }

        TreeNode *root = new TreeNode(postorder[postEnd]);

        int leftSize = i - start;
        int rightSize = end - i;

        root->left = Solve(inorder, postorder, start, i - 1, postStart, postStart + leftSize - 1);
        root->right = Solve(inorder, postorder, i + 1, end, postEnd - rightSize, postEnd - 1);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int postStart = 0;
        int postEnd = postorder.size() - 1;
        return Solve(inorder, postorder, 0, postorder.size() - 1, postStart, postEnd);
    }
};