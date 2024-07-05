// https://leetcode.com/problems/average-of-levels-in-binary-tree/
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
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> result;

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            double sum = 0;
            int save_n = n;

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

            result.push_back(sum / save_n);
        }

        return result;
    }
};