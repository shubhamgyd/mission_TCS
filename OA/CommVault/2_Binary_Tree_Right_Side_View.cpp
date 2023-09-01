/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
*/

#include <bits/stdc++.h>
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

vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        int last = sz - 1;
        for (int i = 0; i < sz; i++)
        {
            auto it = q.front();
            q.pop();
            if (last == i)
            {
                res.push_back(it->val);
            }
            if (it->left)
            {
                q.push(it->left);
            }
            if (it->right)
            {
                q.push(it->right);
            }
        }
    }
    return res;
}

int main()
{
}