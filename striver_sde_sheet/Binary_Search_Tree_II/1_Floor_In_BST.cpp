

#include<bits/stdc++.h>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) , next(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) , next(next) {}
};



void solve(TreeNode* root,int X,int &data)
{
    if(root)
    {
        solve(root->left,X,data);
        if(root->val<=X) data=root->val;
        solve(root->right,X,data);
    }
}

int floorInBST(TreeNode* root, int X)
{
    // Write your code here.
    int data=root->val;
    solve(root,X,data);
    return data;
}