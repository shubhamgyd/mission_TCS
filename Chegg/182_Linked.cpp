#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next; // Pointer to next node
};

struct Node *head = NULL; // Declare Head pointer
struct Node *tail = NULL; // Declare Tail pointer

// Insertion
void insertBegining(int n)
{
    struct Node *newNode = new Node;
    newNode->data = n;
    newNode->next = head;
    head = newNode;
}

// Traverse (print nodes data)
void traverse()
{
    if (head == NULL)
    {
        cout << "Empty List!" << endl;
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Delete last node
void deleteLastNode()
{
    // set pointer to the head
    struct Node *temp = head;

    // if only one node
    // delete head
    if (head->next == NULL)
    {
        // delete head
        delete head;
        // mark as null
        head = NULL;
    }
    // traverse until the second last node
    while (temp->next->next != NULL)
    {
        // go to the next node
        temp = temp->next;
    }
    // delete last node
    delete temp->next;
    // mark the NULL to the next
    temp->next = NULL;
}

// Display last two elements from list
void displayLastTwoElements()
{
    if (head->next == NULL)
    {
        cout << "Only one element : " << head->data << endl;
        return;
    }
    // set pointer to the head
    struct Node *temp = head;

    // traverse until the second last node
    while (temp->next->next)
    {
        // go to the next node
        temp = temp->next;
    }
    // Display last two elements
    cout << temp->data << " " << temp->next->data << endl;
}

// Insert node at any potition
void insertNodeAtN(int n, int val)
{
    // is position is less than equal to 0
    // Invalid position
    if (n <= 0)
    {
        cout << "Invalid position!!" << endl;
        return;
    }
    // get list length
    int length = 0;
    struct Node *curr = head;
    while (curr)
    {
        length++;
        curr = curr->next;
    }
    // if  position is greater than lenght of list +1
    // error : inlvaid position
    if (n > length + 1)
    {
        cout << "Invalid position!!" << endl;
        return;
    }
    // if n==1
    // means insert at the head
    if (n == 1)
    {
        struct Node *newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        return;
    }
    else
    {
        // traverse list until one position before of given position
        struct Node *temp = head;
        for (int i = 1; i < n - 1; i++)
        {
            temp = temp->next;
        }
        // create node node
        struct Node *newNode = new Node;
        newNode->data = val;
        // assing the new link between new node and temp->next
        newNode->next = temp->next;
        // mark the temp->next as new Node
        temp->next = newNode;
        return;
    }
}

int main()
{
    // Insert at the begining
    insertBegining(4);
    insertBegining(2);
    insertBegining(7);
    insertBegining(10);

    // Traverse list
    traverse();
    // Delete last node
    deleteLastNode();
    // traverse list
    traverse();
    // Display last two nodes of list
    displayLastTwoElements();
    // travere list
    traverse();
    // Insert at the nth position
    insertNodeAtN(2, 5);
    // Traverse list
    traverse();
    return 0;
}