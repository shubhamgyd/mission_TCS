#include<bits/stdc++.h>
using namespace std;

struct Tree
{
    int val;
    Tree* left;
    Tree* right;
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



void inorder(Tree* root,map<int,Tree*>mp,vector<bool>&visited)
{
    if(!root)
    {
        return;
    }
    inorder(mp[root->val]->left,mp,visited);
    cout<<root->val<<" ";
    visited[root->val]=true;
    inorder(mp[root->val]->right,mp,visited);
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr1;
    vector<int>arr2;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr1.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr2.push_back(a);
    }

    map<int,Tree*>mp;
    for(auto it:arr1)
    {
        if(mp.find(it)==mp.end())
        {
            mp[it]=new Tree(it);
        }
    }

    for(auto it:arr2)
    {
        if(mp.find(it)==mp.end())
        {
            mp[it]=new Tree(it);
        }
    }

    for(int i=0;i<n;i++)
    {
        int parent,child;
        parent=arr1[i];
        child=arr2[i];
        if(mp[parent]->left==NULL)
        {
            mp[parent]->left=new Tree(child);
        }
        else
        {
            mp[parent]->right=new Tree(child);
        }
    }

    vector<bool>visited(n+1,false);
    for(auto it:mp)
    {
        if(!visited[it.first])
        {
            inorder(it.second->left,mp,visited);
            cout<<it.first<<" ";
            visited[it.first]=true;
            inorder(it.second->right,mp,visited);
        }
    }
}