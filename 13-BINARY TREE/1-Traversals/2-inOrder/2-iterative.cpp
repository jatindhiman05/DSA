#include <iostream>
#include <vector>
#include <stack>
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
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node *root)
    {
        if (!root)
            return {};
        vector<int> result;

        stack<Node *> st;
        Node *curr = root;

        while (curr || !st.empty())
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            result.push_back(curr->data);

            curr = curr->right;
        }

        return result;
    }
};