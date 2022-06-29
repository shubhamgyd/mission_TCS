/*
Problem Statement: Write a program to find the maximum sum path in a binary tree.
A path in a binary tree is a sequence of nodes where every adjacent pair of nodes are
connected by an edge. A node can only appear in the sequence at most once.
A path need not pass from the root. We need to find the path with the maximum
sum in the binary tree.
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

/*
Approach: A brute force approach would be to generate all paths and compare them. 
Generating all paths will be a time-costly activity therefore we need to look for 
something else.

We first need to define what is the maximum path sum through a given node (when that 
node is acting as the root node/curving point). At a given node with a value, if we 
find the max leftSumPath in the left-subtree and the max rightSumPath in the right 
subtree, then the maxPathSum through that node is value+(leftSumPath+rightSumPath).
*/

int solve(TreeNode* root,int &res)
{
    if(!root) return 0;
    int left=solve(root->left,res);
    int right=solve(root->right,res);

    // induction step, wher we will conclude the max path
    int temp=max(max(left,right)+root->val,root->val);
    int ans=max(temp,left+right+root->val);
    res=max(res,ans);
    return temp;
}

int mxPath(TreeNode* root)
{
    int res=INT_MIN;
    solve(root,res);
    return res;
}

/*
Time Complexity: O(N).
Reason: We are doing a tree traversal.

Space Complexity: O(N)
Reason: Space is needed for the recursion stack. 
In the worst case (skewed tree), space complexity can be O(N).
*/

