#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode* next;
    ListNode(int data)
    {
        data=data;
        next=nullptr;
    }
};

int main()
{
    ListNode* head=new ListNode(0);
    // head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;

}