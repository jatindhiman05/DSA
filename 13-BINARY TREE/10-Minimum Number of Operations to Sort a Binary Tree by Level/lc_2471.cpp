#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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
    int minOperations(vector<int> &arr)
    {
        vector<pair<int, int>> valIdx;

        for (int i = 0; i < arr.size(); i++)
        {
            valIdx.push_back({arr[i], i});
        }

        sort(valIdx.begin(), valIdx.end());

        int minSwaps = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            int idx = valIdx[i].second;
            int val = valIdx[i].first;

            if (i != idx)
            {
                swap(valIdx[i], valIdx[idx]);
                minSwaps++;
                i--;
            }
        }

        return minSwaps;
    }

public:
    int minimumOperations(TreeNode *root)
    {
        queue<TreeNode *> q;

        q.push(root);
        int op = 0;

        while (!q.empty())
        {
            int n = q.size();
            vector<int> level;
            while (n--)
            {
                TreeNode *front = q.front();
                q.pop();
                level.push_back(front->val);

                if (front->left)
                {
                    q.push(front->left);
                }

                if (front->right)
                {
                    q.push(front->right);
                }
            }

            // calculate min operations
            op += minOperations(level);
        }

        return op;
    }
};