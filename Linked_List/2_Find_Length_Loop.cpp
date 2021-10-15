#include<bits/stdc++.h>
using namespace std;



struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

int countNodesinLoop(struct Node *head)
{
    // Code here
    // If list is empty or has only one node
    // without loop
    Node *slow=head,*fast=head;
    if(head==NULL || head->next==NULL)
    {
        return 0;
    }

    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow=slow->next;
    fast=fast->next->next;


    // Search for loop using slow and
    // fast pointers
    while(fast && fast->next)
    {
        if(slow==fast)
        {
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    
    // If loop does not exist
    if (slow != fast)
        return 0;


    // If loop exists. Start slow from
    // head and fast from meeting point.    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    //  slow points to the starting point of the loop



    // This one find the length of the loop 
    Node* temp=slow;
    int count=1;
    while(temp->next!=slow)
    {
        count++;
        temp=temp->next;
    }
    return count;
}