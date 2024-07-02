// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode *Solve(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left = Solve(nums, start, mid - 1);
        root->right = Solve(nums, mid + 1, end);

        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return Solve(nums, 0, nums.size() - 1);
    }
};