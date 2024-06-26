#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    vector<int> result;

public:
    // Function to return a list containing the inorder traversal of the tree
    void inorder(Node *root)
    {
        if (!root) return;

        inOrder(root->left);
        result.push_back(root->data);
        inOrder(root->right);
    }
    vector<int> inOrder(Node *root)
    {
        inorder(root);
        return result;
    }
};