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

// Recursion
void preOrder(Node *root, vector<int> &result)
{
    if (!root)
        return;

    result.push_back(root->data);
    preOrder(root->left, result);
    preOrder(root->right, result);
}

vector<int> preorder(Node *root)
{
    vector<int> result;
    preOrder(root, result);
    return result;
}

// using stack

