/*
This problem was asked by Google.

Given a singly linked list and an integer k, remove the kth last 
element from the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.
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

    Node* curr=RemoveLastNode(head,k);
    while(curr)
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    return 0;
}


/*
Renewed Solution
The difference between the final node and the to_be_delete node is N. And here the assumption is that n is always valid.

fast pointer points to the node which is N step away from the to_be_delete node.

slow pointer points to the to_be_delete node.

The algorithms is described as below:

Firstly, move fast pointer N step forward.

Secondly,move fast and slow pointers simultaneously one step a time forward till the fast pointer reach the end, which will cause the slow pointer points to the previous node of the to_be_delete node.

Finally, slow->next = slow->next->next.

ListNode *removeNthFromEnd(ListNode *head, int n) 
{
    if (!head)
        return nullptr;

    ListNode new_head(-1);
    new_head.next = head;

    ListNode *slow = &new_head, *fast = &new_head;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next) 
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *to_de_deleted = slow->next;
    slow->next = slow->next->next;
    
    delete to_be_deleted;

    return new_head.next;
}
*/

