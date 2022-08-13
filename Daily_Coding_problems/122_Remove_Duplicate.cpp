/*
Given a sorted singly linked list, remove all duplicate values and return the modified list.

Ex: Given the following sorted singly linked list…

1->2->2->3, return a list that looks as follows: 1->2->3.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeDuplicate(ListNode* head)
{
    ListNode* temp=head;
    if(!head) return NULL;
    while(temp->next!=NULL and temp!=NULL)
    {
        if(temp->val==temp->next->val)
        {
            ListNode* curr=temp->next;
            temp->next=curr->next;
            delete (curr);
        }
        else temp=temp->next;
    }
    return head;
}

int main()
{
}