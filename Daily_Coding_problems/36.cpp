/*
This question is asked by Google. Given a linked list and a value, 
remove all nodes containing the provided value, and return the resulting list.

Ex: Given the following linked lists and values...

1->2->3->null, value = 3, return 1->2->null
8->1->1->4->12->null, value = 1, return 8->4->12->null
7->12->2->9->null, value = 7, return 12->2->9->null
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
    int val;
    cin>>val;
    Node* curr=head;
    while(curr->val==val && curr)
    {
        curr=curr->next;
    }
    head=curr;
    Node* prev=curr;
    while(curr)
    {
        if(curr->val==val)
        {
            while(curr && curr->val==val)
            {
                curr=curr->next;
            }
            prev->next=curr;
        }
        else
        {
            prev=curr;
            curr=curr->next;
        }
    }
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(1)




// Solution 2:
// if(!head)
        // {
        //     return NULL;
        // }
        // ListNode* curr= removeElements(head->next,val);
        // if(head->val==val)
        // {
        //     return curr;
        // }
        // else
        // {
        //     head->next=curr;
        //     return head;
        // }