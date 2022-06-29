// Problem Statement: Write a program for Morris Inorder Traversal of a Binary Tree.

// In this problem we are going to print the inorder traversal using moris inorder traversal
// it means we are not visitng visited nodes again

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


void morisInorder(TreeNode* root)
{
    TreeNode* curr,*pre;
    curr=root;
    while(curr)
    {
        // if the left subtree is absent, then print data
        if(curr->left==NULL)
        {
            cout<<curr->val<<" ";
            curr=curr->right;
        }
        else
        {
            // now we have to find the inorder predecessor of the current node by traversing
            // current->left->right subtree until we won't get right as a NULL or current node
            pre=curr->left;
            while(pre->right!=NULL or pre->right!=curr)
            {
                pre=pre->right;
            }


            // if we get the pre->right null, then create the safe link 
            // between pre->right=curr
            if(pre->right==NULL)
            {
                pre->right=curr;
                curr=curr->left;
            }
            
            // if we have get the pre->right as a current then we need to remove the safe link between
            // pre and current by setting pre->right=NULL
            else
            {
                pre->right=NULL;
                cout<<curr->val<<" ";
                curr=curr->right;
            }
        }
    }
}

// T:O(n)
// S:O(1)