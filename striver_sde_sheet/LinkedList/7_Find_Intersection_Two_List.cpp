/*
Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Examples:

Example 1:
Input:
List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output:
2
Explanation: Here, both lists intersecting nodes start from node 2.
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

// utility function to check presence of intersection
ListNode *intersectionPresent(ListNode *head1, ListNode *head2)
{
    while (head2 != NULL)
    {
        ListNode *temp = head1;
        while (temp != NULL)
        {
            // if both nodes are same
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    // intersection is not present between the lists return null
    return NULL;
}

/*
Time Complexity: O(m*n)
Reason: For each node in list 2 entire lists 1 are iterated.

Space Complexity: O(1)
Reason: No extra space is used.
*/

// Using Hashing
// Approach:

// Can we improve brute-force time complexity? In brute force, we are basically performing “searching”. We can also perform searches by Hashing. Taking into consideration that hashing process takes O(1) time complexity. So the process is as follows:-

// Iterate through list 1 and hash its node address. Why? (Hint: depends on common attribute we are searching)
// Iterate through list 2 and search the hashed value in the hash table. If found, return node.
// utility function to check presence of intersection
ListNode *intersectionPresent(ListNode *head1, ListNode *head2)
{
    unordered_set<ListNode *> st;
    while (head1 != NULL)
    {
        st.insert(head1);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        if (st.find(head2) != st.end())
            return head2;
        head2 = head2->next;
    }
    return NULL;
}
/*
Time Complexity: O(n+m)
Reason: Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m).

Space Complexity: O(n)
Reason: Storing list 1 node addresses in unordered_set.
*/



// Using Dummy Nodes
// Approach:

// The difference of length method requires various steps to work on it. Using the same concept of difference of length, a different approach can be implemented. The process is as follows:-

// Take two dummy nodes for each list. Point each to the head of the lists.
// Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.


//utility function to check presence of intersection
ListNode* intersectionPresent(ListNode* head1,ListNode* head2) {
    ListNode* d1 = head1;
    ListNode* d2 = head2;
    
    while(d1 != d2) {
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    
    return d1;
}
/*
Time Complexity: O(2*max(length of list1,length of list2))
Reason: Uses the same concept of difference of lengths of two lists.

Space Complexity: O(1)
Reason: No extra data structure is used
*/



int main()
{

}