
/*
Construct A Binary Tree from Inorder and Preorder Traversal

Given the Inorder and Preorder Traversal of a binary tree, we need to construct the 
unique binary tree represented by them.
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

// Intuition:

// Inorder traversal is a special traversal that helps us to identify a node and its 
// left and right subtree. Preorder traversal always gives us the root node as the first
//  element. Using these properties we can construct the unique binary tree.


class Solution {
    TreeNode* bst(map<int,int>&mp,vector<int>& preorder,int& preindex,int i , int j)
    {
        if(i>j)
        {
            return NULL;
        }
        TreeNode *root= new TreeNode(preorder[preindex++]);
        if(i==j)
        {
            return root;
        }
        int mid=mp[root->val];
        root->left=bst(mp,preorder,preindex,i,mid-1);
        root->right=bst(mp,preorder,preindex,mid+1,j);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex=0;
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return bst(mp,preorder,preindex,0,preorder.size()-1);
        
    }
};
// Time Complexity: O(N)

// Assumption: Hashmap returns the answer in constant time.

// Space Complexity: O(N)

// Reason: We are using an external hashmap of size ‘N’.