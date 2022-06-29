/*
Problem Statement: 
Check for Symmetrical Binary Trees

Write a program to check whether a binary tree is symmetrical or not.

Problem Description: 

A symmetrical binary tree is a tree that forms a mirror of itself around the center. 
In other words, every node in the left subtree will have a mirror image in the right subtree.
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

bool solve(TreeNode* root1,TreeNode* root2)
{
    if(!root1 or !root2)
    {
        return (root1==root2);
    }
    return ( root1->val==root2->val and solve(root1->left,root2->right) and solve(root1->right,root2->left));
}

bool isSymmetric(TreeNode* root)
{
    // Write your code here.  
    if(!root) return true;
    return solve(root->left,root->right);
}






class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            TreeNode* node1=q.front();
            q.pop();
            TreeNode* node2=q.front();
            q.pop();
            if(node1 && !node2) return false;
            if(!node1 && node2) return false;
            if(node1 && node2)
            {
                if(node1->val!=node2->val) return false;
                q.push(node1->left);
                q.push(node2->right);
                q.push(node1->right);
                q.push(node2->left);
            }
        }
        return true;
    }
};