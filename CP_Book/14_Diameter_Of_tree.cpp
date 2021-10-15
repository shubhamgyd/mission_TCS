#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        solve(root,dia);
        return dia;
    }
    int  solve(TreeNode* root,int &dia)
    {
        if(!root)
        {
            return 0;
        }
        int ld=solve(root->left,dia);            // Max height of left subtree
        int rd=solve(root->right,dia);           // Max height of right subtree
        dia=max(dia,ld+rd);                      // Max of previous diameter and the current sum of l+r
        return max(ld,rd)+1;                     // Returning the max diameter including root itself
    } 
};