
#include<bits/stdc++.h>
using namespace std;


// a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};
    
struct node* partition(struct node *head,struct node *tail)
{
    struct node *prev=head;
    struct node *curr=head->next;
    struct  node *pivot=head;
    while(curr!=tail->next)
    {
        if(curr->data<pivot->data)
        {
            swap(prev->next->data,curr->data);
            prev=prev->next;
        }
        curr=curr->next;
    }
    swap(pivot->data,prev->data);
    return prev;
}


void QuickSort(struct node *head, struct node *tail)
{
    if(head==NULL || head==tail || tail==NULL)
    {
        return;
    }
    struct node *pIndex=partition(head,tail);
    QuickSort(head,pIndex);
    QuickSort(pIndex->next,tail);
}
void quickSort(struct node **headRef) {
    struct node *tail=*headRef;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    QuickSort(*headRef,tail);
}