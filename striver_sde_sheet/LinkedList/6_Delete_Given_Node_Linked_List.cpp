/*
Problem Statement: Write a function to delete a node in a singly-linked list. 
You will not be given access to the head of the list instead, you will be given 
access to the node to be deleted directly. It is guaranteed that the node to be deleted 
is not a tail node in the list.

Examples:

Example 1:
Input:
 Linked list: [1,4,2,3]
       Node = 2
Output:
Linked list: [1,4,3]
Explanation: Access is given to node 2. After deleting nodes, the linked list will be 
modified to [1,4,3].

Example 2:
Input:
 Linked list: [1,2,3,4]
       Node = 1
Output: Linked list: [2,3,4]
Explanation:
 Access is given to node 1. After deleting nodes, the linked list will be modified to [2,3,4].
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

/*
Approach:

We are given access to nodes that we have to delete from the linked list. 
So, whatever operation we want to do in the linked list, we can operate in 
the right part of the linked list from the node to be deleted. 

The approach is to copy the next node’s value in the deleted node. 
Then, link node to next of next node. This does not delete that node but
 indirectly it removes that node from the linked list.
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};


/*
Basically we are just copying node's next value to itself
Input: 1->2->3->4->5 ->6
given node = 4
output: 1->2->3->5->6

1. in first step: node->val becomes node's next ki value i.e 4 becomes 5
1->2->3->5->5->6
2. in 2nd step: node points to node's next next i.e 5->6
1->2->3->5->6
*/

int main()
{
    bitset<32>b(8);
    cout<<b<<endl;
    bitset<8>b1(11);
    cout<<b1<<endl;
    bitset<8>b2(7);
    cout<<b2<<endl;
    string ans=bitset<32>(8).to_string().substr(32 - log2(8));
    cout<<ans<<endl;
}