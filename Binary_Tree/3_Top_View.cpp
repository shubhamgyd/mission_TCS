#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> topView(Node *root)
{
    vector<int>v;
    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));;
    while(!q.empty())
    {
        int count=q.size();
        while(count--)
        {
            pair<Node*,int>curr=q.front();
            q.pop();
            if(mp.find(curr.second)==mp.end())
            {
                mp[curr.second]=curr.first->data;
            }
            if(curr.first->left)
            {
                q.push(make_pair(curr.first->left,curr.second-1));
            }
            if(curr.first->right)
            {
                q.push(make_pair(curr.first->right,curr.second+1));
            }
        }
    }
    for(auto it:mp)
    {
        v.push_back(it.second);
    }
    return v;
        
    }