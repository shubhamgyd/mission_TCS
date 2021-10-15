#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};


void Insert(Node *&head3,int data,Node *&last)
{
       struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
       newNode->data=data;
       newNode->next=NULL;
       
       if(last==NULL){
           head3=newNode;
       }
       else{
           last->next=newNode;
       }
       last=newNode;
}

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node* head3;
    Node* last=NULL;
    map<int,int>mp;
    while(head1!=NULL)
    {
        //uset.insert(head1->data);
        mp[head1->data]++;
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        if(mp.find(head2->data)!=mp.end())
        {
            Insert(head3,head2->data,last);
            mp.erase(head2->data);
        }
        head2=head2->next;
    }
    return head3;
}