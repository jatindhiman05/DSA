#include<iostream>
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

class info
{
public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

class Solution
{
public:
    info solve(Node *root, int &maxisize)
    {
        if (root == NULL)
        {
            return {INT_MAX, INT_MIN, true, 0};
        }

        info left = solve(root->left, maxisize);
        info right = solve(root->right, maxisize);

        info currNode;
        currNode.size = left.size + right.size + 1;
        currNode.maxi = max(root->data, right.maxi);
        currNode.mini = min(root->data, left.mini);

        if (left.isBST and right.isBST and (left.maxi < root->data and root->data < right.mini))
            currNode.isBST = true;

        else
            currNode.isBST = false;

        if (currNode.isBST)
        {
            maxisize = max(currNode.size, maxisize);
        }

        return currNode;
    }

    int largestBst(Node *root)
    {
        int maxisize = 0;
        info temp = solve(root, maxisize);
        return maxisize;
    }
};