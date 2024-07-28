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
public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inOrder(Node *root, vector<int> &arr)
    {
        if (!root)
            return;
        inOrder(root->left, arr);
        arr.push_back(root->data);
        inOrder(root->right, arr);
    }

    vector<int> mergeSortedArray(vector<int> a, vector<int> b)
    {
        vector<int> res;
        int i = 0, j = 0;
        for (i = 0, j = 0; i < a.size() && j < b.size();)
        {
            if (a[i] <= b[j])
                res.push_back(a[i++]);
            else
                res.push_back(b[j++]);
        }
        for (; i < a.size(); i++)
            res.push_back(a[i]);
        for (; j < b.size(); j++)
            res.push_back(b[j]);
        return res;
    }
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> a, b;
        inOrder(root1, a);
        inOrder(root2, b);
        return mergeSortedArray(a, b);
    }
};