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
    ListNode *merge(ListNode *a, ListNode *b)
    {
        ListNode *result = NULL;
        if (a == NULL)
        {
            return b;
        }
        else if (b == NULL)
        {
            return a;
        }
        if (a->val <= b->val)
        {
            result = a;
            result->next = merge(a->next, b);
        }
        else
        {
            result = b;
            result->next = merge(a, b->next);
        }
        return result;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        if (k == 0)
        {
            return NULL;
        }
        for (int i = 1; i < k; i++)
        {
            lists[0] = merge(lists[0], lists[i]);
        }
        return lists[0];
    }
};