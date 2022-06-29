/*
Problem Statement: Find the Diameter of a Binary Tree. Diameter is the length of the 
longest path between any 2 nodes in the tree and this path may or may not pass from the root
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

int solve(TreeNode* root ,int &dia)
{
    if(!root) return 0;
    int left=solve(root->left,dia);
    int right=solve(root->right,dia);
    dia=max(dia,left+right);
    return max(left,right)+1;
}

int Diameter(TreeNode* root)
{
    int dia=0;
    solve(root,dia);
    return dia;
}
// T:O(n)
// S:O(1)