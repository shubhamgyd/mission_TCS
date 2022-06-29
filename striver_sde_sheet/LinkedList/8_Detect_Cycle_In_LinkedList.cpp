/*
Problem Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.

Return true if there is a cycle in the linked list. Otherwise, return false.

Examples:

Example 1:
Input:
 Head = [1,2,3,4]
Output:
 true
Explanation: Here, we can see that we can reach node at position 1 again by following the next pointer. Thus, we return true for this case.

*/

#include <bits/stdc++.h>
using namespace std;

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

// Using Hashing
// Approach:

// We need to keep track of all the nodes we have visited till now so that once we
// visit the same node again we can say that a cycle is detected.
// The process is as follows:

// Use a hash table for storing nodes.
// Start iterating through the lists.
// If the current node is present in the hash table already,
// this indicates the cycle is present in the linked list and returns true.
// Else move insert the node in the hash table and move ahead.
// If we reach the end of the list, which is NULL, then we can say that
// the given list does not have a cycle in it and hence we return false.


//utility function to detect cycle
bool cycleDetect(ListNode *head) {
    unordered_set<ListNode*> hashTable;
    while(head != NULL) {
        if(hashTable.find(head) != hashTable.end()) return true;
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}
/*
Time Complexity: O(N)
Reason: Entire list is iterated once.

Space Complexity: O(N)
Reason: All nodes present in the list are stored in a hash table.
*/




// Using slow and faster pointer
// Approach:

// We will use two pointers with different steps forward. The process is as follows:-

// We will take two pointers, namely fast and slow. Fast pointer takes 2 steps ahead and slow pointer takes 2 points ahead.
// Iterate through the list until the fast pointer is equal to NULL. This is because NULL indicates that there is no cycle present in the given list.
// Cycle can be detected when fast and slow pointers collide.

//utility function to detect cycle
bool cycleDetect(ListNode* head) {
    if(head == NULL) return false;
    ListNode* fast = head;
    ListNode* slow = head;
        
    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}

/*
Time Complexity: O(N)
Reason: In the worst case, all the nodes of the list are visited.

Space Complexity: O(1)
Reason: No extra data structure is used.
*/

int main()
{
    
}