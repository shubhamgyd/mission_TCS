#include<bits/stdc++.h>
using namespace std;



struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void Inorder(Node* root1,vector<int>&v)
{
    if(!root1)
    {
        return;
    }
    Inorder(root1->left,v);
    v.push_back(root1->data);
    Inorder(root1->right,v);
}


void Inorder1(Node* root2,unordered_map<int,int>&mp1)
{
    if(!root2)
    {
        return;
    }
    Inorder1(root2->left,mp1);
    mp1[root2->data]++;
    Inorder1(root2->right,mp1);
}

int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    unordered_map<int,int>mp;
    vector<int>v;
    Inorder(root1,v);
    unordered_map<int,int>mp1;
    Inorder1(root2,mp1);
    int count=0;
    for(auto it:v)
    {
        if(mp1.find(x-it)!=mp1.end())
        {
            count++;
        }
    }
    return count;
}