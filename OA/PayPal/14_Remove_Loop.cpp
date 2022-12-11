#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

void removeLoop(Node *head)
{
    // code here
    // just remove the loop without losing any nodes
    Node *slow = head, *fast = head;
    // slow=slow->next;
    // fast=fast->next;
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow == head)
    {
        while (slow->next != head)
        {
            slow = slow->next;
        }
        slow->next = NULL;
    }

    if (slow == fast)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            if (slow == fast->next)
            {
                fast->next = NULL;
            }
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}