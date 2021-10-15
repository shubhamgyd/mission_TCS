#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution{
  public:
    int helper(Node* root,bool &ans)
    {
        if(!root) return 0;
        int l=helper(root->left,ans);
        int r=helper(root->right,ans);
        if(root->left && root->right && l!=r)
        {
            ans=false;
        }
        return 1+max(l,r);
    }
    
    bool check(Node *root)
    {
        bool ans=true;
        helper(root,ans);
        return ans;
    }
};