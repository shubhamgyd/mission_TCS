/*
his question is asked by Facebook. Given a linked list, containing unique values, reverse it, 
and return the result.

Ex: Given the following linked lists...

1->2->3->null, return a reference to the node that contains 3 which points to a list 
that looks like the following: 3->2->1->null
7->15->9->2->null, return a reference to the node that contains 2 which points to a 
list that looks like the following: 2->9->15->7->null
1->null, return a reference to the node that contains 1 which points to a list that 
looks like the following: 1->null
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int data)
    {
        val=data;
        next=NULL;
    }
};


void Insert(Node *&head3,int data,Node *&last)
{
       struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

int main()
{
    int n;
    cin>>n;
    Node* head;
    Node* last=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        Insert(head,a,last);
    }
    Node* curr=head,*prev=NULL,*next;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(1)