/*
This problem was asked by PayPal.

Given a binary tree, determine whether or not it is height-balanced. 
A height-balanced binary tree can be defined as one in which the heights of the two subtrees of 
any node never differ by more than one.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
};

int postOrder(TreeNode* root,bool &ans)
{
    if(!root) return 0;
    int left=postOrder(root->left,ans);
    int right=postOrder(root->right,ans);

    int diff=abs(left-right);
    if(diff>1)
    {
        ans=false;
        return 0;
    }
    return max(left,right)+1;
}

bool isBalanced(TreeNode* root)
{
    bool ans=true;
    return postOrder(root,ans);
    return ans;

}

int main()
{

}