#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
    Node()
    {
        val=0;
        left=NULL;
        right=NULL;
    }
    Node(int data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
};


void Inorder(int node,map<int,Node*>&mp)
{
    if(mp.find(node)!=mp.end())
    {
        if(mp[node]->left)
        {
            Inorder(mp[node]->left->val,mp);
        }
        cout<<node<<" ";
        if(mp[node]->right)
        {
            Inorder(mp[node]->right->val,mp);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    map<int,Node*>mp;
    for(auto it:arr1)
    {
        if(mp.find(it)==mp.end())
        {
            mp[it]= new Node();
        }
    }

    for(auto it:arr2)
    {
        if(mp.find(it)==mp.end())
        {
            mp[it]= new Node();
        }
    }


   for(int i=0;i<n;i++)
   {
       int parent=arr1[i];
       int child=arr2[i];
       if(mp[parent]->left==NULL)
       {
           mp[parent]->left=new Node(child);
       }
       else
       {
           mp[parent]->right=new Node(child);
       }
   }

   Inorder(1,mp);

    

}