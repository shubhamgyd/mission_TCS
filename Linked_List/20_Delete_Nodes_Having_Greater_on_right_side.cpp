#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head->next==NULL)
        {
            return head; 
        }
        struct Node *temp=compute(head->next);
        if(temp->data>head->data)
        {
            return temp;
        }
        else
        {
            head->next=temp;
        }
        
        return head;
    }
    
};