#include<bits/stdc++.h>
using namespace std;


 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


// By using two pointer method

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // ListNode *slow=head,*fast=head->next;
        // if(head->next==nullptr)
        // {
        //     return head;
        // }
        // while(fast->next && fast->next->next)
        // {
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        // return slow->next;
        ListNode *slow=head;
        ListNode *fast=head;
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};