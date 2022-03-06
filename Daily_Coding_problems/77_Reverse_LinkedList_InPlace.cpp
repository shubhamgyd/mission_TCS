/*
This problem was asked by Google.

Given the head of a singly linked list, reverse it in-place.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int data)
    {
        val=data;
        next=NULL;
    }
};




int main()
{
    Node *root= new Node(0);
    root->next=new Node(1);
    root->next->next=new Node(2);
    root->next->next->next=new Node(3);

    Node* curr=root,*prev=NULL,*next;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    root=prev;
    while(root)
    {
        cout<<root->val<<" ";
        root=root->next;
    }
    return 0;
}