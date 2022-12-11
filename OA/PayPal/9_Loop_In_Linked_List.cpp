#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

int startingPointLoop(ListNode *head)
{
    if (!head)
    {
        return -1;
    }

    ListNode *fast = head->next;
    ListNode *slow = head;

    while (fast != slow)
    {
        if (!fast || !fast->next)
        {
            return -1;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

int main()
{
}