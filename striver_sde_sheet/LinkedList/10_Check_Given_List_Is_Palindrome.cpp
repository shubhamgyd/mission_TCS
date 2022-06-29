/*
Problem Statement: Given the head of a singly linked list, return true if it is a palindrome.

Examples:

Example 1:
Input: head = [1,2,3,3,2,1] 
Output:
 true
Explanation: If we read elements from left to right, 
we get [1,2,3,3,2,1]. When we read elements from right to left, 
we get [1,2,3,3,2,1]. Both ways list remains same and hence, 
the given linked list is palindrome.
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


// Brute Force
bool isPalindrome(ListNode* head) {
    vector<int> arr;
    while(head != NULL) {
        arr.push_back(head->val);
        head = head->next;
    }
    
    for(int i=0;i<arr.size()/2;i++) 
        if(arr[i] != arr[arr.size()-i-1]) return false;
    return true;
}
/*
Time Complexity: O(N)
Reason: Iterating through the list to store elements in the array.

Space Complexity: O(N)
Reason: Using an array to store list elements for further computations.
*/


// Optimize
ListNode* reverse(ListNode* ptr) {
    ListNode* pre=NULL;
    ListNode* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}

bool isPalindrome(ListNode* head) {
    if(head==NULL||head->next==NULL) return true;
        
    ListNode* slow = head;
    ListNode* fast = head;
        
    while(fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
        
    slow->next = reverse(slow->next);
    slow = slow->next;
    ListNode* dummy = head;
        
    while(slow!=NULL) {
        if(dummy->val != slow->val) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}
// Time Complexity: O(N/2)+O(N/2)+O(N/2)
// Reason: O(N/2) for finding the middle element, reversing the list from the middle element, and traversing again to find palindrome respectively.

// Space Complexity: O(1)
// Reason: No extra data structures are used.


int main()
{

}