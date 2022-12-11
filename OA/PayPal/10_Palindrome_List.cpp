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

bool isPalindrome(ListNode *head)
{
    ListNode *prev = NULL, *nextn = NULL, *slow = head, *fast = head;
    if (!head || head->next == NULL)
        return true;
    while (fast and fast->next)
    {
        if (fast->next)
            fast = fast->next->next;
        nextn = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextn;
    }
    if (fast != NULL)
        nextn = nextn->next;
    while (prev and nextn)
    {
        if (prev->data != nextn->data)
            return false;
        prev = prev->next;
        nextn = nextn->next;
    }
    return prev == nextn;
}

int main()
{
}