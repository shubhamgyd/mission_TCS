#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

class LinkedIntList
{
private:
    ListNode *front; // nullptr for an empty list
public:
    LinkedIntList();
    void addFront(int value);
    bool isSorted();
};

LinkedIntList::LinkedIntList()
{
    front = nullptr;
}

void LinkedIntList::addFront(int value)
{
    ListNode *temp = new ListNode;
    temp->data = value;
    temp->next = front;
    front = temp;
}

bool LinkedIntList::isSorted()
{
    if (front == nullptr)
    { // empty list
        return true;
    }

        ListNode *current = front;
    int prevData = current->data;
    while (current->next != nullptr)
    {
        current = current->next;
        if (prevData > current->data)
        { // list is not sorted
            return false;
        }
        prevData = current->data;
    }

    return true; // list is sorted
}

int main()
{
    LinkedIntList myList;
    myList.addFront(3);
    myList.addFront(2);
    myList.addFront(1);
    std::cout << "Is the list sorted? " << std::boolalpha << myList.isSorted() << std::endl;

    myList.addFront(4);

    std::cout << "Is the list sorted? " << std::boolalpha << myList.isSorted() << std::endl;

    return 0;
}
