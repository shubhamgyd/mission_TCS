
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

TreeNode* solve(TreeNode* root,int data)
{
    if(!root)
    {
        root=new TreeNode(data);
        return root;
    }
    if(data<=root->val)
    {
        root->left=solve(root->left,data);
    }
    else
    {
        root->right=solve(root->right,data);
    }
    return root;
}

TreeNode* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    TreeNode* root=NULL;
    for(int i=0;i<preOrder.size();i++)
    {
        root=solve(root,preOrder[i]);
    }
    return root;
}