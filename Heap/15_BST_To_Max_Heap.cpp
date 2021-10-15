#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution{
    void inorder(Node* root,vector<int>&v)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    void BuildHeap(Node* root,vector<int>&v,int *i)
    {
        if(!root)
        {
            return;
        }
        BuildHeap(root->left,v,i);
        BuildHeap(root->right,v,i);
        root->data=v[++*i];
    }
  public:
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int>v;
        inorder(root,v);
        int i=-1;
        BuildHeap(root,v,&i);
        
    }    
};