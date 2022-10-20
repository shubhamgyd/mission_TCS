#include <iostream>
using namespace std;

// Structure to store the nodes
struct Node
{
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

// keep track on size of list
int length = 0;

// Function which insert the value x at ith position
void Insert(Node **head, int x, int i)
{
    // base condition
    // if position is valid or not
    if (i < 0 or i > length + 1)
    {
        cout << "Invalid position!!\n";
        return;
    }
    // go to the ith position and add newNode with value x
    for (int j = 0; j < i; j++)
    {
        // Insert value at ith position
        // here i-1 because we starte from 0th position
        if (j == i - 1)
        {
            // get new node with value x
            Node *currNode = new Node(x);
            // modify the next edge of head
            currNode->next = *head;
            // update head
            *head = currNode;
        }
        else
        {
            // go to the next position
            // by making the double pointer
            head = &(*head)->next;
        }
    }
    // Increase the length of list by 1
    length++;
}

// Function which remove the value at ith position
void Remove(Node **head, int i)
{
    // base condition
    if (*head == NULL)
    {
        cout << "List empty!!" << endl;
        return;
    }
    // if position is less than 0 or greater than the length of list
    if (i < 0 or i > length)
    {
        cout << "Invalid position!!\n";
        return;
    }
    // store the head
    Node *currNode = *head;
    // if position is 0 means we need to remove head
    if (i == 0)
    {
        *head = currNode->next;
        free(currNode);
        return;
    }
    int pos = 0;
    // go the the one element behind the position to delete the link
    // and make the new link
    while (pos < i - 2 and currNode != NULL)
    {
        currNode = currNode->next;
        pos++;
    }
    // if number is greater than the length of list
    if (currNode == NULL or currNode->next == NULL)
        return;
    // update the link
    // and remove the ith element
    currNode->next = currNode->next->next;
    // decrease the length of list by 1
    length--;
}

// Function which set the value x of ith elements
void Set(Node **head, int x, int i)
{
    // base condition
    // if position is less than length size or greater than length size
    if (i < 0 or i > length)
    {
        cout << "Invalid positon!!" << endl;
        return;
    }
    // Iterate till the ith position
    int pos = 0;
    Node *currNode = *head;
    while (pos < i - 1)
    {
        currNode = currNode->next;
        pos++;
    }
    // set the value of ith element = x
    currNode->val = x;
}

// Function which return the ith element value
int Get(Node **head, int i)
{
    // base condition
    // if position is less than length size or greater than length size
    if (i < 0 or i > length)
    {
        cout << "Invalid positon!!" << endl;
        return -1;
    }
    // Iterate till ith element
    int pos = 0;
    Node *currNode = *head;
    while (pos < i - 1)
    {
        currNode = currNode->next;
        pos++;
    }
    // return the ith element value
    return currNode->val;
}

// Function which prints the list
void Print(Node *head)
{
    // base condition
    // if list empty
    if (head == NULL)
    {
        cout << "List is empty!!" << endl;
        return;
    }
    // print list
    cout << "List: ";
    Node *currNode = head;
    while (currNode != NULL)
    {
        cout << currNode->val << "->";
        currNode = currNode->next;
    }
    cout << "NULL";
    cout << endl;
}

int main()
{
    // Make head = NULL
    Node *head = NULL;
    while (true)
    {
        // Options
        cout << endl;
        cout << "1. Get Length\n";
        cout << "2. Insert\n";
        cout << "3. Remove\n";
        cout << "4. Set\n";
        cout << "5. Get\n";
        cout << "6. Print\n";

        // input option
        int option;
        cin >> option;
        // get length
        if (option == 1)
        {
            cout << "Length of list: " << length << endl;
        }
        // Insert element
        else if (option == 2)
        {
            int num, pos;
            cout << "Enter value to insert: ";
            cin >> num;
            cout << "Enter position to insert: ";
            cin >> pos;
            Insert(&head, num, pos);
        }
        // Remove element
        else if (option == 3)
        {
            int pos;
            cout << "Enter position to remove: ";
            cin >> pos;
            Remove(&head, pos);
        }
        // Set value at position
        else if (option == 4)
        {
            int num, pos;
            cout << "Enter value to set: ";
            cin >> num;
            cout << "Enter position to set: ";
            cin >> pos;
            Set(&head, num, pos);
        }
        // get value at positon
        else if (option == 5)
        {
            int pos;
            cout << "Enter position to get value: ";
            cin >> pos;
            int num = Get(&head, pos);
            if (num == -1)
                continue;
            else
            {
                cout << "Element at positon " << pos << " = " << num << endl;
            }
        }
        // Print list
        else if (option == 6)
        {
            Print(head);
        }
    }
}