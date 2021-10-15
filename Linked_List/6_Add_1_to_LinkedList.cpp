
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

int carry;
class Solution
{
    void helper(Node* head)
    {
        if(!head)
        {
            return;
        }
        helper(head->next);
        head->data=head->data+carry;
        carry=head->data/10;
        head->data=head->data%10;
    }
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        carry=1;
        helper(head);
        if(carry)
        {
            Node* newNode =(struct Node*)malloc(sizeof(struct Node));
            newNode->data=carry;
            newNode->next=head;
            head=newNode;
        }
        return head;
    }
};