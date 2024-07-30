#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    void solve(Node *root, int k, int &ans)
    {
        if (root == NULL)
            return;

        int temp = abs(root->data - k);
        if (temp < ans)
            ans = temp;

        solve(root->left, k, ans);
        solve(root->right, k, ans);
    }

    int minDiff(Node *root, int K)
    {
        int ans = INT_MAX;
        solve(root, K, ans);
        return ans;
    }
};