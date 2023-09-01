#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
    {
        // ListNode *pA = headA;
        // ListNode *pB = headB;
        // // cout<<pA->val<<" "<<pB->val<<endl;
        // while (pA != pB) {
        //     pA = pA == nullptr ? headB : pA->next;
        //     pB = pB == nullptr ? headA : pB->next;
        //     // if(pA) cout<<pA->val<<" ";
        //     // if(pB) cout<<pB->val<<" ";
        //     // cout<<endl;
        //     // cout<<pA->val<<" "<<pB->val<<endl;
        // }
        // return pA;
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
};