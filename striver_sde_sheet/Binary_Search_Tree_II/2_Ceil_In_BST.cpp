#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), next(next) {}
};
void solve(TreeNode *root, int x, int &data, long int &dist)
{
    if (root)
    {
        solve(root->left, x, data, dist);
        if (root->val >= x)
        {
            long int diff = root->val- x;
            //             cout<<"root->val: "<<root->data<<" x:"<<x<<" diff: "<<diff<<endl;
            if (diff < dist)
            {
                dist = diff;
                data = root->val;
            }
        }
        solve(root->right, x, data, dist);
    }
}

int findCeil(TreeNode *node, int x)
{
    // Write your code here.
    int data = -1;
    long int dist = 1e9;
    solve(node, x, data, dist);
    return data;
}