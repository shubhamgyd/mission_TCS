/*
Problem Statement: Morris Preorder Traversal of a Binary tree. Given a Binary Tree,
find the Morris preorder traversal of Binary Tree.
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


void MorisPreorder(TreeNode* root)
{
    while(root)
    {
        // if left subtree is absent
        if(root->left==NULL)
        {
            cout<<root->left<<" ";
            root=root->right;
        }
        else
        {
            // now we have to find the preorder successor of the current node by traversing
            // curr->left->right subtree until we won't get right as a NULL or current node
            TreeNode* pre=root->left;
            while(pre->right!=NULL or pre->right!=root)
            {
                pre=pre->right;
            }


            // now, if the right of the current is null then we have to generate the
            // safe link between current node to the root node
            if(pre->right==NULL)
            {
                // by the rule of preorder
                cout<<root->val<<" ";

                // generate safe link 
                pre->right=root;

                //move root to left
                root=root->left;
            }

            // or else if the right of the current node is not NULL or root node
            // then remove the safe link and move the root to the right
            else
            {
                pre->right=NULL;
                root=root->right;
            }
        }
    }

}
// T:O(n)
// S:O(1)


int main()
{

}