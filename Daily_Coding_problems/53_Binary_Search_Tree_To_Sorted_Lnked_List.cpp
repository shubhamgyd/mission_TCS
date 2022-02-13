#include<bits/stdc++.h>
using namespace std;

struct Tree
{
    int val;
    Tree* left;
    Tree* right;
};

struct Node
{
    int val;
    Node *next;
};



void Insert(Node *&head3,int data,Node *&last)
{
       Node* newNode = new Node();
       newNode->val=data;
       newNode->next=NULL;
       
       if(last==NULL){
           head3=newNode;
       }
       else{
           last->next=newNode;
       }
       last=newNode;
}

void inorder(Tree *root,Node *head,Node* last)
{
    if(!root)
    {
        return;
    }
    inorder(root->left,head,last);
    Insert(head,root->val,last);
    inorder(root->right,head,last);
}
// Time Complexity:O(h)
// Space Complexity:O(n)

int main()
{
    Tree *root;
    Node *head;
    Node *last=NULL;
    inorder(root,head,last);
}