#include<bits/stdc++.h>
using namespace std;


struct Node{
        int data;
        struct Node* next;
};

struct Node* head;
void Insert(int data,int n)
{
     Node* temp=new Node();
     temp->data=data;
     temp->next=NULL;
     if(n==1)
     {
         temp->next=head;
         head=temp;
         return;
     }
     Node* temp1=head;
     for(int i=0;i<n-2;i++)
     {
        temp1=temp1->next;
     }
     temp->next=temp1->next;
     temp1->next=temp;
}

void Print()
{
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

void moveToFirst(Node **head,int m)
{
    Node* temp=*head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }

    int rem=count-m;
    
    temp=*head;
    Node* prev=NULL;
    for(int i=0;i<rem;i++)
    {
        
        prev=temp;
        temp=temp->next;
    }

    Node* curr=temp;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    prev->next=NULL;
    curr->next=*head;
    *head=temp;
}
int main(){
        head=NULL;
        Insert(2,1);
        Insert(3,2);
        Insert(4,3);
        Insert(5,4);
        Insert(6,5);
        Insert(7,6);
        Print();
        int m=3;
        moveToFirst(&head,m);
        Print();
        return 0;
}