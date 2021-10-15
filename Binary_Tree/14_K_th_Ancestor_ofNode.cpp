#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node* solve(Node* root,int &k,int node,int &ans)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==node ||(solve(root->left,k,node,ans)) || 
    (solve(root->right,k,node,ans)))
    {
        if(k>0)
        {
            k--;
        }
        else if(k==0)
        {
            ans=root->data;
            return NULL;
        }
        return root;
        
    }
}
int kthAncestor(Node *root, int k, int node)
{
    // Code her
    if(!root)
    {
        return -1;
    }
    int ans=-1;
    solve(root,k,node,ans);
    return ans;
}