/*
In this article we will solve the most asked coding interview question: ” Merge two sorted Linked Lists “

Problem Statement: Given two singly linked lists that are sorted in increasing order of node values, merge two sorted linked lists and return them as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Example 1:

Input Format :
l1 = {3,7,10}, l2 = {1,2,5,8,10}

Output :
{1,2,3,5,7,8,10,10}
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

// Approach 1: Brute Force
// Using Externally List


// Apprach 2: Using Inplace Method without using extra space
class Solution {

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // when list1 is empty then 
        // our output will be same as list2
        if(l1 == NULL) return l2; 

        // when list2 is empty then our output 
        // will be same as list1
        if(l2 == NULL) return l1;

        // pointing l1 and l2 to smallest and greatest one
        if(l1->val > l2->val) std::swap(l1,l2);

        // act as head of resultant merged list
        ListNode* res = l1;

        while(l1 != NULL && l2 != NULL) {
 
            ListNode* temp = NULL;

            while(l1 != NULL && l1->val <= l2->val) {

                temp = l1;//storing last sorted node  
                l1 = l1->next;
            }

            // link previous sorted node with 
            // next larger node in list2
            temp->next = l2;
            std::swap(l1,l2);
        }

        return res;
    }
};

/*
Time Complexity :

We are still traversing both lists entirely in the worst-case scenario. 
So, it remains the same as O(N+M) where N is the number of nodes in list 1 and M is the number of nodes in list 2.

Space Complexity :

We are using the same lists just changing links to create our desired list. 
So no extra space is used. Hence, its space complexity is O(1). 
*/


// Using Merge Sort : Recursive Method
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res=NULL;
        if(!l1)
        {
            return l2;
        }
        else if(!l2)
        {
            return l1;
        }
        if(l1->val<=l2->val)
        {
            res=l1;
            res->next=mergeTwoLists(l1->next,l2);
        }
        else
        {
            res=l2;
            res->next=mergeTwoLists(l1,l2->next);
        }
        return res;
    }
};

