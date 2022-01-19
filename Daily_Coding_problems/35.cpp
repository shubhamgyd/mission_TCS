/*
This question is asked by Facebook. Given a linked list and a value n, 
remove the nth to last node and return the resulting list.

Ex: Given the following linked lists...

1->2->3->null, n = 1, return 1->2->null
1->2->3->null, n = 2, return 1->3->null
1->2->3->null, n = 3, return 2->3->null
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

Node* RemoveLastNode(Node* head,int k)
{

    int len=0;
    Node* curr=head;
    while(curr)
    {
        len++;
        curr=curr->next;
    }
    if(k==len)
    {
        return head=head->next;
    }
    len=len-k-1;
    curr=head;
    while(len)
    {
        len--;
        curr=curr->next;
    }
    curr->next=curr->next->next;
    return head;

}


int main()
{
    Node* head;
    Node* last=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        Insert(head,a,last);
    }
    int k;
    cin>>k;

    

}