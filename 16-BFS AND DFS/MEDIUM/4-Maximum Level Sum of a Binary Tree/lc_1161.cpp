// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        int maxLevel = 0;
        int maxSum = INT_MIN;
        int level = 1;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            int sum = 0;

            while (n--)
            {
                TreeNode *front = q.front();
                q.pop();

                sum += front->val;

                if (front->left)
                {
                    q.push(front->left);
                }

                if (front->right)
                {
                    q.push(front->right);
                }
            }

            if (sum > maxSum)
            {
                maxSum = sum;
                maxLevel = level;
            }

            level++;
        }

        return maxLevel;
    }
};