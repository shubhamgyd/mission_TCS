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

Node *removeDuplicates(Node *head)
{
 // your code goes here
 //unordered_map<int,int>mp;
 struct Node *temp=head;
    while(temp->next!=NULL &&temp!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            Node *curr=temp->next;
            //temp->data=curr->data;
            temp->next=curr->next;
            delete(curr);
        }
        else temp=temp->next;
    }
    return head;
}