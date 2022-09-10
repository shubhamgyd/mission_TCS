/*
Given a binary tree, invert it and return the resulting tree.

Ex: Given the following binary tree…

        1
       /  \
      2    3, return...
         1
        /  \
       3    2
Ex: Given the following binary tree…

        1
       /  \
      2     3
     / \   /  \
    4   5 6    7, return...
         1
        /  \
       3     2
     /   \  /  \
    7    6 5    4 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
};

Node* invertBinaryTree(Node* root)
{
    if(!root) return root;
    Node* temp=new Node(root->val);
    temp->left=invertBinaryTree(root->right);
    temp->right=invertBinaryTree(root->left);
    return temp;
}


int main()
{

}