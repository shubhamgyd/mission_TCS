

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

void findPreSuc(TreeNode *root, TreeNode *&pre, TreeNode *&suc, int key)
{
    if (!root)
        return;
    else if (key == root->val)
    {
        if (root->right)
        {
            suc = root->right;
            while (suc->left)
                suc = suc->left;
        }
        if (root->left)
        {
            pre = root->left;
            while (pre->right)
                pre = pre->right;
        }
    }
    else if (key < root->val)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}