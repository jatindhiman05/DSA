#include <iostream>
#include <vector>
#include <queue>
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
    void levelorder(Node *root)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *front = q.front();
            result.push_back(front->data);
            q.pop();

            if (front->left)
            {
                q.push(front->left);
            }

            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
    // Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node *root)
    {
        levelorder(root);
        return result;
    }
};