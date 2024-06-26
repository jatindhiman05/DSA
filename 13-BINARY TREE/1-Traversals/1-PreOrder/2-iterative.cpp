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

vector<int> preorder(Node *root)
{
    if (!root)
        return {};

    vector<int> result;
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *front = st.top();
        st.pop();
        result.push_back(front->data);

        if (front->right)
        {
            st.push(front->right);
        }

        if (front->left)
        {
            st.push(front->left);
        }
    }

    return result;
}