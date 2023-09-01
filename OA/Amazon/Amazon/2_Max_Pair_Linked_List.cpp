#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int data)
    {
        val=data;
        next=nullptr;
    }
};

int max_val;
ListNode* tmp;

void maxPair(ListNode* p) {
    if(p == NULL) {
        return;
    }
    maxPair(p->next);
    max_val = max(max_val, p->val + tmp->val);
    tmp = tmp->next;
}
void solve(ListNode* head)
{
    max_val = INT_MIN;
    tmp = head;
    maxPair(head);
    cout<<"Result is "<<max_val<<"\n";
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(11);
    solve(head);
}