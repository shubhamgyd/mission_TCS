

#include<bits/stdc++.h>
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

void solve(TreeNode* root,vector<int>&res)
{
    if(root)
    {
        solve(root->left,res);
        res.push_back(root->val);
        solve(root->right,res);
    }
}
bool validateBST(TreeNode *root) {
    // Write your code here
    vector<int>res;
    solve(root,res);
    if(is_sorted(res.begin(),res.end())) return true;
    return false;
}