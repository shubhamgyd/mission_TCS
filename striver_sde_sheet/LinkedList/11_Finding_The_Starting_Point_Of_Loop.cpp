/*
Problem Statement: Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that the tail’s next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Examples:

Example 1:
Input:
 head = [1,2,3,4,3,6,10]
Output:
 tail connects to node index 2
*/

#include<bits/stdc++.h>
using namespace std;



// Brute Force
// Approach:

// We can store nodes in a hash table so that, if a loop exists, the head will encounter the same node again. This node will be present in the table and hence, we can detect the loop. Steps are:-

// Iterate the given list.
// For each node visited by head pointer, check if node is present in the hash table.
// If yes, loop detected
// If not, insert node in the hash table and move the head pointer ahead.
// If head reaches null, then the given list does not have a cycle in it.



class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};

//process as per mentioned in solution
node* detectCycle(node* head) {
    unordered_set<node*> st;
    while(head != NULL) {
        if(st.find(head) != st.end()) return head;
        st.insert(head);
        head = head->next;
    }
    return NULL;
}



// Using Two Pointer
//process as per mentioned in solution
node* detectCycle(node* head) {
    if(head == NULL||head->next == NULL) return NULL;
        
    node* fast = head;
    node* slow = head;
    node* entry = head;
        
    while(fast->next != NULL&&fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
            
        if(slow == fast) {
            while(slow != entry) {
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;
}



// After returning node, just count the index of that node

int main()
{

}