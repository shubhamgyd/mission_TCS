#include <iostream>
using namespace std;

// Structure of LinkedList Node
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL){};
};

Node *purge(Node *head, int key)
{
    // base condition
    // if head is NULL
    if (head == NULL)
    {
        return NULL;
    }
    // point to the head
    Node *currentNode = head;
    // Iterate until head value is equal to the key
    while (currentNode and currentNode->data == key)
    {
        // go to the next node
        currentNode = currentNode->next;
    }
    // assign new head at currentNode
    head = currentNode;
    // point prevNode to the previous of currentNode
    Node *prevNode = currentNode;
    // Iterate LinkedList
    while (currentNode)
    {
        // if we get the node with the value is equal to the key
        if (currentNode->data == key)
        {
            // Iterate until we get the node value equal to the key
            while (currentNode and currentNode->data == key)
            {
                // go to the next node
                currentNode = currentNode->next;
            }
            // update the previos node so it will reflect in original head node
            prevNode->next = currentNode;
        }
        else
        {
            // keep link between last node and current Node
            prevNode = currentNode;
            // go to the next node
            currentNode = currentNode->next;
        }
    }
    // return the updated head node
    return head;
}

int main()
{
    // Make linkelist
    // 1->2->2->3->2->4
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(4);
    // Display list without removing key
    Node *curr = head;
    cout << "LinkedList before removing key-> ";
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    int key = 2;
    Node *updatedHead = purge(head, key);
    // Display list aster removing all occurances of key
    cout << "key = " << key << endl;
    cout << "LinkedList after removing key-> ";
    while (updatedHead)
    {
        cout << updatedHead->data << " ";
        updatedHead = updatedHead->next;
    }
    cout << endl;
    return 0;
}