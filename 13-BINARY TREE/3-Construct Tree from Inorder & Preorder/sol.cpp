// https://www.geeksforgeeks.org/problems/construct-tree-1
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    Node *Solve(int in[], int pre[], int start, int end, int &idx)
    {
        if (start > end)
        {
            return NULL;
        }

        int rootVal = pre[idx];
        int i = start;

        for (; i <= end; i++)
        {
            if (in[i] == rootVal)
            {
                break;
            }
        }

        idx++;

        Node *root = new Node(rootVal);

        root->left = Solve(in, pre, start, i - 1, idx);
        root->right = Solve(in, pre, i + 1, end, idx);

        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        int idx = 0;

        return Solve(in, pre, 0, n - 1, idx);
    }
};