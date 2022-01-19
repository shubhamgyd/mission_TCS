/*
This problem was asked by Google.

Given two singly linked lists that intersect at some point, find the intersecting node. 
The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};



int getCount(Node* h)
{
    int ct=0;
    while(h!=NULL)
    {
        ct++;
        h=h->next;
    }
    return ct;
}

int _getIntersectionNode(int rem,Node* h1,Node* h2)
{
    Node* curr1=h1;
    Node* curr2=h2;
    for(int i=0;i<rem;i++)
    {
        if(curr1==NULL)
        {
            return -1;
        }
        curr1=curr1->next;
    }

    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->data==curr2->data)
        {
            return curr1->data;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return -1;
}

int interSection(Node* h1,Node* h2)
{
    int ct1=getCount(h1);
    int ct2=getCount(h2);
    int rem;
    if(ct1>ct2)
    {
        rem=ct1-ct2;
        return _getIntersectionNode(rem,h1,h2);
    }
    else
    {
        rem=ct2-ct1;
        return _getIntersectionNode(rem,h2,h1);
    }
}
// Time Complexity:O(m+n)
// Space Complexity:O(1)




int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_set<Node*>s;
    while(head1)
    {
        s.insert(head1);
        head1=head1->next;
    }
    while(head2)
    {
        if(s.find(head2)!=s.end())
        {
            return head2->data;
        }
        head2=head2->next;
    }
    return -1;
}
// Time Complexity:O(m+n)
// Space Complexity:O(m)


int main()
{
    Node* newNode;
 
    // Addition of new nodes
    Node* head1 = new Node();
    head1->data = 10;
 
    Node* head2 = new Node();
    head2->data = 3;
 
    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;
 
    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;
 
    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
 
    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;
 
    head1->next->next->next = NULL;
    cout<<interSection(head1,head2)<<endl;
    return 0;
}