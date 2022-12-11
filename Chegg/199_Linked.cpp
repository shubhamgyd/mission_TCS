#include <bits/stdc++.h>
using namespace std;

// Structure of linkedlist
struct linkedlist
{
    int data;
    linkedlist *next;
    linkedlist(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert(linkedlist *&head, linkedlist *&last, int data)
{
    // Generate new node
    linkedlist *newNode = new linkedlist(data);
    // If lst node is null then mark newNode as a head
    if (last == NULL)
    {
        head = newNode;
    }
    // else update the last of next is newNode
    else
    {
        last->next = newNode;
    }
    // and point last to the newNode
    last = newNode;
}

void reverseLinkedList(linkedlist **head)
{
    linkedlist *current = *head;
    linkedlist *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        // move next to current of next
        next = current->next;
        // mark current of next as previous
        current->next = prev;
        // move prev to current
        prev = current;
        // move current to next
        current = next;
    }
    *head = prev;
}

int main()
{
    // Input of number of elements in a linkedlist
    cout << "Enter number of elements in linkedlist: ";
    int n;
    cin >> n;
    // head of linkedlist
    linkedlist *head = NULL;
    // last node
    linkedlist *last = NULL;
    // Input of elements
    for (int i = 1; i <= n; i++)
    {
        // Input number
        cout << "Enter the " << i << " element of linkedlist: ";
        int num;
        cin >> num;
        // Insert at the tail of linkedlist
        insert(head, last, num);
    }
    cout << endl;
    // Print given linkedlist
    cout << "*** Given linked list\n";
    linkedlist *curr = head;
    while (curr != NULL)
    {
        if (curr->next == NULL)
        {
            cout << curr->data << "->";
            cout << "NULL\n";
        }
        else
        {
            cout << curr->data << "->";
        }
        curr = curr->next;
    }
    // Function call to reverse linkedlist
    // and passed head by reference
    reverseLinkedList(&head);
    cout << endl;

    // Print reverse linkedlist
    cout << "*** Reversed linked list\n";
    curr = head;
    while (curr != NULL)
    {
        if (curr->next == NULL)
        {
            cout << curr->data << "->";
            cout << "NULL\n";
        }
        else
        {
            cout << curr->data << "->";
        }
        curr = curr->next;
    }
    return 0;
}