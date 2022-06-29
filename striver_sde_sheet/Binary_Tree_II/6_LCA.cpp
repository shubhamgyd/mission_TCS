/*
Problem Statement: Given a binary tree, Find the Lowest Common Ancestor for two given 
Nodes (x,y).

Lowest Common Ancestor(LCA): The lowest common ancestor is defined between two nodes 
x and y as the lowest node in T that has both x and y as descendants 
(where we allow a node to be a descendant of itself.
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

TreeNode* LCAA(TreeNode*root,int a,int b)
{
    if(!root) return NULL;
    if(root->val==a or root->val==b)
    {
        return root;
    }
    TreeNode* left=LCAA(root->left,a,b);
    TreeNode* right=LCAA(root->right,a,b);
    if(left and right)
    {
        return root;
    }
    if(left) return left;
    return right;
}

int findDistance(TreeNode* root,int a,int step)
{
    if(!root) return -1;
    if(root->val==a) return step;
    int l=findDistance(root->left,a,step+1);
    if(l!=-1)
    {
        return l;
    }
    return findDistance(root->right,a,step+1);
}

int LCA(TreeNode* root,int A,int B)
{
    TreeNode* node=LCAA(root,A,B);
    int d1=findDistance(node,A,0);
    int d2=findDistance(node,B,0);
    return d1+d2;
}

// Time complexity: O(N) where n is the number of nodes.
// Space complexity: O(N), auxiliary space.