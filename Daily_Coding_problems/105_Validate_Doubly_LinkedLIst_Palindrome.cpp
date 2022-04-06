/*
This problem was asked by Google.

Determine whether a doubly linked list is a palindrome. What if it’s singly linked?

For example, 1 -> 4 -> 3 -> 4 -> 1 returns True while 1 -> 4 returns False.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};


/* Given a reference (pointer to pointer) to
   the head of a list and an int, inserts a
   new node on the front of the list. */
void push(struct Node** head_ref, char new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
    (*head_ref)    = new_node;
}

bool isPalindrome(struct Node *head)
{
    if(!head) return false;
    struct Node* front=head;
    while(front->next!=NULL)
    {
        front=front->next;
    }
    while(front!=head)
    {
        if(front->data!=head->data) return false;
        front=front->prev;
        head=head->next;
    }
    return true;
}
// Time Complexity:O(n)
// Space Complexity:O(1)

int main()
{
    struct Node* head = NULL;
    push(&head, 'l');
    push(&head, 'e');
    push(&head, 'v');
    push(&head, 'e');
    push(&head, 'l');

    bool ok=isPalindrome(head);
    if(ok)
    {
        cout<<"Palindromic Doubly LinkeList"<<endl;
    }
    else{
        cout<<"Non Palindromic Doubly LinkedList"<<endl;
    }
    return 0;
}