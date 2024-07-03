// https://leetcode.com/problems/maximum-binary-tree/
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
    TreeNode *Solve(vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        int max_idx = -1;
        int max = INT_MIN;

        for (int i = start; i <= end; i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                max_idx = i;
            }
        }

        TreeNode *root = new TreeNode(max);

        root->left = Solve(nums, start, max_idx - 1);
        root->right = Solve(nums, max_idx + 1, end);

        return root;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return Solve(nums, 0, nums.size() - 1);
    }
};
