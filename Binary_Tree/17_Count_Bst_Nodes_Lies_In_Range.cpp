#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

void count(Node* root,int &c,int l,int h)
{
    if(!root)
    {
        return;
    }
    if(root->data>=l && root->data<=h)
    {
        c++;
    }
    count(root->left,c,l,h);
    count(root->right,c,l,h);
}

//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
  // your code goes here   
  int c=0;
  count(root,c,l,h);
  return c;
}