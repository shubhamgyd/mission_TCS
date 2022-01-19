/*
This question is asked by Apple. Given two sorted linked lists, merge
them together in ascending order and return a reference to the merged list

Ex: Given the following lists...

list1 = 1->2->3, list2 = 4->5->6->null, return 1->2->3->4->5->6->null
list1 = 1->3->5, list2 = 2->4->6->null, return 1->2->3->4->5->6->null
list1 = 4->4->7, list2 = 1->5->6->null, return 1->4->4->5->6->7->null
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


Node* Sort(Node *h1,Node *h2)
{
    Node* current=NULL;
    if(!h1)
    {
        return h2;
    }
    if(!h2)
    {
        return h1;
    }
    if(h1->val<=h2->val)
    {
        current=h1;
        current->next=Sort(h1->next,h2);
    }
    else
    {
        current=h2;
        current->next=Sort(h1,h2->next);
    }
    return current;

}

int main()
{
    Node* l1;
    Node* prev=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        Insert(l1,a,prev);
    }
    Node* l2;
    prev=NULL;
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        Insert(l2,a,prev);
    }
    Node* head=Sort(l1,l2);
    Node* curr=head;
    while(curr)
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    return 0;

}

/*
Time Complexity:  Since we are traversing through the two lists fully. So, the time 
complexity is O(m+n) where m and n are the lengths of the two lists to be merged. 
*/