// https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/
#include <iostream>
#include <queue>
#include <vector>
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
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        if (!root)
            return {};

        vector<int> result;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            Node *temp;
            while (n--)
            {
                temp = q.front();
                q.pop();

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

            result.push_back(temp->data);
        }

        return result;
    }
};