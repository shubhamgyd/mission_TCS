/*
Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

Examples:

Input Format:
head = [3,6,8,10]
This means the given linked list is 3->6->8->10 with head pointer at node 3.

Result:
Output = [10,6,8,3]
This means, after reversal, the list should be 10->6->8->3 with the head pointer at node 10.
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

// Iterative
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head, *next, *prev = NULL;
        while (curr)
        {
            //   go to the next noe
            next = curr->next;

            // reverse the link
            curr->next = prev;

            // step one step of previous node to generate other links
            prev = curr;

            // go the next node
            curr = next;
        }
        // mark last node as head
        head = prev;

        // return head
        return head;
    }
};

// Recursive
// Intuition: This approach is very similar to the above 3 pointer approach.
// In the process of reversing, the base operation is manipulating the pointers of each node
// and at the end, the original head should be pointing towards NULL and the original last
// node should be ‘head’ of the reversed Linked List.

class Solution1
{
    ListNode *solve(ListNode *head)
    {
        // Base Case
        if (!head->next or head == NULL)
        {
            return head;
        }
        ListNode *node = solve(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }

public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return NULL;
        return solve(head);
    }
};
// We move to the end of the list and achieve our reversed list. Thus, the time complexity is O(N) where N represents the number of nodes.

// Space Complexity:

// Apart from recursion using stack space, no external storage is used. Thus, space complexity is O(1).

int main()
{
}