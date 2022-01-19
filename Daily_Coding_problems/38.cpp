/*
This question is asked by Amazon. Given a non-empty linked list, 
return the middle node of the list. If the linked list contains an even number of elements, return the node closer to the end.
Ex: Given the following linked lists...

1->2->3->null, return 2
1->2->3->4->null, return 3
1->null, return 1
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


// simple appraoch , two passing
int MidElement(Node* head)
{
    Node* curr=head;
    int len=1;
    while(curr->next)
    {
        len++;
        curr=curr->next;
    }
    curr=head;
    len/=2;
    for(int i=0;i<len;i++)
    {
        curr=curr->next;
    }
    return curr->val;
}
// Time Complexity:O(n)
// Space Complexity:O(1)



// optimise version
int Mid(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    if(!head && head->next==NULL)
    {
        return head->val;
    }
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->val;
}
// Two pointers approach
// Time complexity:O(n)
// Space Complxity:O(1)


int main()
{
    Node* head;
    Node* last=NULL;
    int  n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        Insert(head,a,last);
    }
    cout<<MidElement(head)<<endl;
    cout<<Mid(head)<<endl;
    return 0;
}