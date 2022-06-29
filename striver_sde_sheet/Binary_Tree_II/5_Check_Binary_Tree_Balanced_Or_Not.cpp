/*
Problem Statement: Check whether the given Binary Tree is a Balanced Binary Tree or not. 
A binary tree is balanced if, for all nodes in the tree, the difference between left and right 
subtree height is not more than 1.
*/

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

int solve(TreeNode* root,bool &isValid)
{
    if(!root) return 0;
    int left=solve(root->left,isValid);
    int right=solve(root->right,isValid);
    if(abs(left-right)>1)
    {
        isValid=false;
    }
    return max(left,right)+1;
}

bool isBalanced(TreeNode* root)
{
    if(!root) return true;
    bool isValid=true;
    solve(root,isValid);
    return isValid;
}
/*
Time Complexity: O(N) 
Space Complexity: O(1) Extra Space + O(H) Recursion Stack space (Where “H”  is the height of binary tree)
*/