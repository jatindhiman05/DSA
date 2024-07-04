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

// dfs
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return 1;

        int left = root->left ? minDepth(root->left) : INT_MAX;
        int right = root->right ? minDepth(root->right) : INT_MAX;

        return 1 + min(left, right);
    }
};

// bfs
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        if (!root->left && !root->right)
        {
            return 1;
        }

        queue<TreeNode *> q;
        q.push(root);

        int depth = 1;

        while (!q.empty())
        {
            int n = q.size();

            while (n--)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (!temp->left && !temp->right)
                {
                    return depth;
                }

                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            depth++;
        }

        return -1;
    }
};