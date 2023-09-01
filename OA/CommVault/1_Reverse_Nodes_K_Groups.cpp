/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    ListNode *reverse(ListNode *first, ListNode *last)
    {
        ListNode *prev = last;
        while (first != last)
        {
            ListNode *tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }
        return prev;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // Reverse k nodes
        auto node = head;
        for (int i = 0; i < k; i++)
        {
            if (!node)
            {
                return head;
            }
            node = node->next;
        }
        auto new_node = reverse(head, node);
        // Reverse next k nodes and so on
        head->next = reverseKGroup(node, k);
        return new_node;
    }
};
// Time Complexity:O(n)
// Space Complexity:O(k)

int main()
{
}