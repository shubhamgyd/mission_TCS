

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
    void preOrder(TreeNode *root, TreeNode *&curr)
    {
        if (root == NULL)
        {
            return;
        }
        curr->left = NULL;
        curr->right = root;
        curr = root;
        preOrder(root->left, curr);
        preOrder(root->right, curr);
    }

public:
    void flatten(TreeNode *root)
    {
        TreeNode *dummy = new TreeNode(-1);
        TreeNode *res = root;
        TreeNode *curr = dummy;
        preOrder(root, curr);

        curr->left = NULL;
        curr->right = NULL;
        // root=dummy->right;
        res = dummy->right;
        delete dummy;
    }
};