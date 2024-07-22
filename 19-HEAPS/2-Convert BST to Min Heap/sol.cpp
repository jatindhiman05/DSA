// https://www.naukri.com/code360/problems/convert-bst-to-min-heap_920498
#include <iostream>
#include <vector>
using namespace std;

class BinaryTreeNode
{

public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
void getinorder(BinaryTreeNode *root, vector<int> &v)
{

    if (!root)
    {
        return;
    }

    getinorder(root->left, v);

    v.push_back(root->data);

    getinorder(root->right, v);
}

void fillpreorder(BinaryTreeNode *&root, vector<int> inorder, int &i)
{

    if (!root)
    {
        return;
    }

    root->data = inorder[i++];

    fillpreorder(root->left, inorder, i);

    fillpreorder(root->right, inorder, i);
}

BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    vector<int> inorder;

    getinorder(root, inorder);

    int i = 0;

    fillpreorder(root, inorder, i);

    return root;
}