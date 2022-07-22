/*
Problem Statement: Given the head of a linked list, rotate the list to the right by k places.

Examples:

Example 1:
Input:
    head = [1,2,3,4,5]
    k = 2
Output:
 head = [4,5,1,2,3]
Explanation:
 We have to rotate the list to the right twice.

*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int num;
    node *next;
    node(int a)
    {
        num = a;
        next = NULL;
    }
};

// utility function to rotate list by k times
node *rotateRight(node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    for (int i = 0; i < k; i++)
    {
        node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        node *end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}

/*
Time Complexity: O(Number of nodes present in the list*k)
Reason: For k times, we are iterating through the entire list to get the last element and move it to first.

Space Complexity: O(1)
Reason: No extra data structures is used for computations
*/

// utility function to rotate list by k times
node *rotateRight(node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    // calculating length
    node *temp = head;
    int length = 1;
    while (temp->next != NULL)
    {
        ++length;
        temp = temp->next;
    }
    // link last node to first node
    temp->next = head;
    k = k % length;       // when k is more than length of list
    int end = length - k; // to get end of the list
    while (end--)
        temp = temp->next;
    // breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;

    return head;
}
/*
Time Complexity: O(length of list) + O(length of list – (length of list%k))
Reason: O(length of the list) for calculating the length of the list. O(length of the list – (length of list%k)) for breaking link.

Space Complexity: O(1)
*/