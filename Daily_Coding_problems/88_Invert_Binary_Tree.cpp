/*
This problem was asked by Google.

Invert a binary tree.

For example, given the following tree:

    a
   / \
  b   c
 / \  /
d   e f
should become:

  a
 / \
 c  b
 \  / \
  f e  d
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
};

Tree* InvertBinaryTree(Tree* root)
{
    if(!root)
    {
        return root;
    }
    Tree* temp=new Tree(root->val);
    temp->right=InvertBinaryTree(root->left);
    temp->left=InvertBinaryTree(root->right);
    return temp;
}
// time complexity:O(n)
// auxiliary space: O(n)



void Inorder(Tree* root)
{
    if(!root)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}

int main()
{
    Tree *root=new Tree(1);
    root->left= new Tree(2);
    root->right=new Tree(3);
    root->left->left=new Tree(4);
    root->left->right=new Tree(5);
    root->right->left=new Tree(6);
    root->right->right=new Tree(7);
    Inorder(root);
    Tree* newRoot=InvertBinaryTree(root);
    cout<<endl;
    Inorder(newRoot);
    return 0;
}