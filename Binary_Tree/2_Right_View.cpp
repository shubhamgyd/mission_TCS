#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>v;
       if(!root)
       {
           return v;
       }
       int ct=0;
       int count=0;
       queue<Node*>q;
       q.push(root);
       while(!q.empty())
       {
           count=q.size();
           while(count--)
           {
               Node* curr=q.front();
               q.pop();
               if(ct==0)
               {
                   v.push_back(curr->data);
               }
               ct++;
               if(curr->right)
               {
                   q.push(curr->right);
               }
               if(curr->left)
               {
                   q.push(curr->left);
               }
           }
           ct=0;
       }
       return v;
    }
};