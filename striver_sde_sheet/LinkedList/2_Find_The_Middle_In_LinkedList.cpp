/*
Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

Examples:

Input Format: 
( Pointer / Access to the head of a Linked list )
head = [1,2,3,4,5]

Result: [3,4,5]
( As we will return the middle of Linked list the further linked list will be still available )

Explanation: The middle node of the list is node 3 as in the below image.
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


// Naieve Approach
/*
Intuition: We can traverse through the Linked List while maintaining a 
count of nodes let’s say in variable n , and then traversing for 2nd time for 
n/2 nodes to get to the middle of the list.
*/

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
    	int n = 0;
    	ListNode* temp = head;
    	while(temp) {
        	n++;
        	temp = temp->next;
    	}
   	 
    	temp = head;
   	 
    	for(int i = 0; i < n / 2; i++) {
        	temp = temp->next;
    	}
   	 
    	return temp;
	}
};
// T:O(n)
// S:O(1)



// Efficient Approach
/*
Intuition: In the Tortoise-Hare approach, we increment slow ptr by 1 and fast ptr by 2, 
so if take a close look fast ptr will travel double than that of the slow pointer. 
So when the fast ptr will be at the end of Linked List, slow ptr would have covered 
half of Linked List till then. So slow ptr will be pointing towards the middle of Linked List.
*/

class Solution1 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};
// T:O(n)
// S:O(1)s