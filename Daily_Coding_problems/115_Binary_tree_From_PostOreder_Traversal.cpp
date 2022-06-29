/*
This problem was asked by Google.

Given the sequence of keys visited by a postorder traversal of a binary search tree, reconstruct the tree.

For example, given the sequence 2, 4, 3, 8, 7, 5, you should construct the following tree:

    5
   / \
  3   7
 / \   \
2   4   8
*/

#include<bits/stdc++.h>
using namespace std;

struct Tree
{
    int val;
    Tree *left;
    Tree *right;
    Tree(int data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
    Tree()
    {
        val=0;
        left=NULL;
        right=NULL;
    }
};


Tree* postToBinary(int start,int end,vector<int>&res)
{
    if(start>end)
    {
        return NULL;
    }
    Tree *node=new Tree(res[end]);
    // cout<<node->val<<endl;
    int i;
    for(i=end;i>=start;i--)
    {
        if(res[i]<node->val)
        {
            break;
        }
    }
    node->right=postToBinary(i+1,end-1,res);
    node->left=postToBinary(start,i,res);
    return node;
}

void inorder(Tree* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    Tree *root=postToBinary(0,n-1,res);
    inorder(root);
}