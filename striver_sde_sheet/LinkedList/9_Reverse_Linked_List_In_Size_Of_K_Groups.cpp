/*
Problem Statement: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Examples:

Example 1:
Input:
 head = [1,2,3,4,5,6,7,8] k=3
Output:
 head = [3,2,1,6,5,4,7,8]
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//utility function to find length of the list
int lengthOfLinkedList(ListNode* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}

//utility function to reverse k nodes in the list
ListNode* reverseKNodes(ListNode* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    
    int length = lengthOfLinkedList(head);
    
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    
    ListNode* pre = dummyHead;
    ListNode* cur;
    ListNode* nex;
    
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;
}

// Time Complexity: O(N)
// Reason: Nested iteration with O((N/k)*k) which makes it equal to O(N).

// Space Complexity: O(1)
// Reason: No extra data structures are used for computation.