/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *res = NULL;
        if (!l1)
        {
            return l2;
        }
        else if (!l2)
        {
            return l1;
        }
        if (l1->val <= l2->val)
        {
            res = l1;
            res->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            res = l2;
            res->next = mergeTwoLists(l1, l2->next);
        }
        return res;
    }
};