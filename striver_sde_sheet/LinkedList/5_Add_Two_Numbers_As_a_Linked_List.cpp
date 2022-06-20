/*
Problem Statement: Given the heads of two non-empty linked lists representing 
two non-negative integers. The digits are stored in reverse order, and each of 
their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

Examples:

Input Format: 
(Pointer/Access to the head of the two linked lists)

num1  = 342, num2 = 564

l1 = [2,4,3]
l2 = [5,6,4]

Result: sum = 807; L = [7,0,8]
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


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);
        ListNode *temp=head;
        int carrysum=0;
        while(l1!=nullptr || l2!=nullptr || carrysum)
        {
            int x=l1?l1->val:0;
            int y=l2?l2->val:0;
            int tm=x+y+carrysum;
            // tmp=8
            temp->next=new ListNode(tm%10);
            carrysum=tm/10;
            temp=temp->next;
            l1=l1?l1->next:nullptr;
            l2=l2?l2->next:nullptr;
        }
        return head->next;
    }
};

/*
Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 
respectively, the algorithm above iterates at most max(m,n) times.

Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.
*/

int main()
{

}