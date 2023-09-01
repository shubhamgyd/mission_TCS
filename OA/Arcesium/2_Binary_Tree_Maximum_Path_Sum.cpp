/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
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

class Solution
{
    int diameter(TreeNode *root, int &res)
    {
        // Base condition
        if (root == NULL)
        {
            return 0;
        }

        // Hypothesis step ..this both conditions will find task automatically , we don't have to think
        // it
        int l = diameter(root->left, res);
        int r = diameter(root->right, res);

        // Induction step .. here we have to implement some relation
        // like
        int temp = max(max(l, r) + root->val, root->val);
        int ans = max(temp, l + r + root->val);
        res = max(res, ans);
        return temp;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        diameter(root, res);
        return res;
    }
};