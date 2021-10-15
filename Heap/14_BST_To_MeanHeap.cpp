/*
Given a binary search tree which is also a complete binary tree. The problem is to convert the given 
BST into a Min Heap with the condition that all the values in the left subtree of a node should be 
less than all the values in the right subtree of the node. This condition is applied on all the 
nodes in the so converted Min Heap. 
Examples: 
 

Input :          4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output :        1
              /   \
             2     5
           /  \   /  \
          3   4  6    7 
*/

#include<bits/stdc++.h>
using namespace std;

struct BstNode {
        int data;
        BstNode* left;
        BstNode* right;
};
BstNode*  GetNewNode(int data){
       BstNode* newNode = new BstNode();
       newNode->data=data;
       newNode->left=NULL;
       newNode->right=NULL;
       return newNode;

}

BstNode* Insert(BstNode* root,int data){
      if(root==NULL)
      {
              root=GetNewNode(data);
              return root;
      }
      else if(data<=root->data)
      {
              root->left=Insert(root->left,data);
      }
      else
      {
              root->right=Insert(root->right,data);
      }
      return root;
}

// function for the inorder traversal of the tree
// so as to store the node values in 'arr' in
// sorted order
void inorder(BstNode* root,vector<int>&v)
{
    if(!root)
    {
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

// function to convert the given BST to MIN HEAP
// performs preorder traversal of the tree
void BuildMeanHeap(BstNode* root,vector<int>&v,int i)
{
    if(!root)
    {
        return;
    }
    root->data=v[++i];
    BuildMeanHeap(root->left,v,i);
    BuildMeanHeap(root->right,v,i);
}
void BSTtoMinHeap(BstNode *root)
{
    vector<int>v;
    inorder(root,v);
    int i=-1;
    BuildMeanHeap(root,v,i);
}

void Inorder(BstNode* root)
{
    if(!root)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void PreOrder(BstNode* root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
int main()
{
    BstNode* root=NULL;
   root=Insert(root,7);
   root=Insert(root,1);
   root=Insert(root,2);
   root=Insert(root,4);
   root=Insert(root,6);
   root=Insert(root,3);
   root=Insert(root,5);
   PreOrder(root);
   BSTtoMinHeap(root);
   cout<<endl;
   PreOrder(root);
   return 0;
}