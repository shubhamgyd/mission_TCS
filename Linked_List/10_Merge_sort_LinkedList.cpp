#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};



class Solution{
    void Splitting(Node* head,Node **a,Node **b)
    {
        // By using two pointer method wesplit the linked list  int two different part
        Node *fast=head->next;
        Node *slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        *a=head;
        *b=slow->next;
        slow->next=NULL;
        //                   slow              --> fast=NULL
        //  example  1--->2--->3 | --->4--->5--->NULL
        //                     pivot
    }
    
    Node* Sort(Node *a,Node *b)
    {
        Node *answer=NULL;
        // if a is null
        if(a==NULL)
        {
            return b;
        }

        // if b is null
        if(b==NULL)
        {
            return a;
        }

        // similar to array merge sort
        if(a->data<=b->data)
        {
            answer=a;
            answer->next=Sort(a->next,b);
        }
        else
        {
            answer=b;
            answer->next=Sort(a,b->next);
        }
        return answer;
    }
    
    // Function works to split the linked list in different parts
    void Merge(Node **headref)
    {
        Node *head= *headref;
        if(head==NULL || head->next==NULL)
        {
            return;
        }
        Node *a, *b;
        Splitting(head,&a,&b);                       // Splitting linkedlist 
        Merge(&a);                                   // Recursive call to split the list until one element is remain
        Merge(&b);
        *headref=Sort(a,b);                          // finally merge the splitted linked list in sorted order
    }
    
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        Merge(&head);                   // Passing head as reference , so that we can get the updated head
        return head;
    }
};