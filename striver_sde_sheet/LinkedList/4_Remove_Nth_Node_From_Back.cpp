/*
Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linkedlist, and delete it. Return the head of the new modified linked list.

Example 1 : 

Input: head = [1,2,3,4,5], n = 2

Output: [1,2,3,5]
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

/*
Solution 1: Naive Approach [Traverse 2 times]

Intuition: We can traverse through the Linked List while maintaining a count of nodes,
let’s say in variable count , and then traversing for the 2nd time for (n – count) 
nodes to get to the nth node of the list.
*/


/*
Solution 2: [Efficient] Two pointer method

Unlike the above approach, we don’t have to maintain the count value, we can find 
the nth node just by one traversal by using two pointer approach.

Intuition : 

What if we had to modify the same above approach to work in just one traversal? 
Let’s see what all information we have here:

We have the flexibility of using two-pointers now.
We know, the n-th node from the end is the same as (total nodes – n)th node from start.
But, we are not allowed to calculate total nodes, as we can do only one traversal.
What if, one out of the two-pointers is at the nth node from start instead of end? 
Will it make anything easier for us?

Yes, with two pointers in hand out of which one at n-th node from start, we can just 
advance both of them till end simultaneously, once the faster reaches the end, the 
slower will stand at the n-th node from the end.

*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
};





class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
        {
            return head;
        }
        int len=0;
        ListNode* curr=head;
        while(curr)
        {
            len++;
            curr=curr->next;
        }
            // cout<<len<<endl;
        if(n==len)
        {
            return head=head->next;
        }
        len=len-n-1;
        curr=head;
        while(len)
        {
            len--;
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};