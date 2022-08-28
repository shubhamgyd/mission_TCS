/*
A boring tree is a tree whose nodes only contain a single value. Given a reference to the root of a binary tree, root, return whether or not it is a boring tree.
Note: It is guaranteed that a single value exists within the tree.

Ex: Given the following root…

       7
      / \
     7   7, return true.
Ex: Given the following root…

       1
      / \
     2   3, return false.
*/

#include<bits/stdc++.h>
using namespace std;

struct Tree
{
    int val;
    Tree* left;
    Tree* right;
};

void isBoaring(Tree* root,set<int>&st)
{
    if(!root) return;
    st.insert(root->val);
    isBoaring(root->left,st);
    isBoaring(root->right,st);
}