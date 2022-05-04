/*
Given two linked lists that represent two numbers, return the sum of the numbers also represented as a list.

Ex: Given the two linked lists…

a = 1->2, b = 1->3, return a list that looks as follows: 2->5
Ex: Given the two linked lists…

a = 1->9, b = 1, return a list that looks as follows: 2->0
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};


Node* reverseList(Node *head)
{
    Node *curr=head,*next,*prev=NULL;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}

Node* listSum(Node *l1,Node *l2)
{
    l1=reverseList(l1);
    l2=reverseList(l2);

    int carry=0;
    Node *sumHead=new Node(0);
    Node *dummy=sumHead;
    while(l1 || l2|| carry)
    {
        int num1=l1?l1->data:0;
        int num2=l2?l2->data:0;
        int total=num1+num2+carry;
        carry=total/10;
        int rem=total%10;
        Node *temp=new Node(rem);
        dummy->next=temp;
        dummy=temp;
        l1=l1?l1->next:NULL;
        l2=l2?l2->next:NULL;
    }
    sumHead=reverseList(sumHead->next);
    return sumHead;
}
// Time Complexity:O(n)+O(max(n,m))+O(n) 
//                i.e O(max(n,m))

// Space Complexity:O(max(n,m))



int main()
{
    

}