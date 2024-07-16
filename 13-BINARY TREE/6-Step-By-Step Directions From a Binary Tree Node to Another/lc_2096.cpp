#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// approach 1 create graph and perform bfs to find shortest path
class Solution
{
public:
    void createGraph(unordered_map<int, vector<pair<int, char>>> &adj, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left)
        {
            adj[root->val].push_back({root->left->val, 'L'});
            adj[root->left->val].push_back({root->val, 'U'});
            createGraph(adj, root->left);
        }

        if (root->right)
        {
            adj[root->val].push_back({root->right->val, 'R'});
            adj[root->right->val].push_back({root->val, 'U'});
            createGraph(adj, root->right);
        }
    }

    string getDirections(TreeNode *root, int start, int dest)
    {
        unordered_map<int, vector<pair<int, char>>> adj;
        createGraph(adj, root);

        vector<bool> vis(1000001, 0);
        vector<int> path(1000002, -1);
        vector<char> dir(1000002);

        queue<int> q;
        q.push(start);
        vis[start] = true;
        path[start] = -1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (node == dest)
                break;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                char adjDir = it.second;

                if (!vis[adjNode])
                {
                    vis[adjNode] = 1;
                    path[adjNode] = node;
                    dir[adjNode] = adjDir;
                    q.push(adjNode);
                }
            }
        }

        string ans = "";
        while (path[dest] != -1)
        {
            ans += dir[dest];
            dest = path[dest];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};