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
    Node *flattenBST(Node *root)
    {
        if (!root)
        {
            return NULL;
        }
        Node *head = flattenBST(root->left);
        root->left = NULL;

        if (head)
        {
            Node *temp = head;
            while (temp->right)
            {
                temp = temp->right;
            }
            temp->right = root;
        }
        else
        {
            head = root;
        }

        root->right = flattenBST(root->right);

        return head;
    }
};