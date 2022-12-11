#include <iostream>
using namespace std;

// Structure to store the student information
struct Student
{
    // variables to store id and name
    string sid, name;
    Student *next;
    // Default constructor
    Student()
    {
        sid = "0";
        name = "";
        next = NULL;
    }
    // Paramaterize constructor
    Student(string id, string sName)
    {
        this->sid = id;
        this->name = sName;
        next = NULL;
    }
};

// Insert data into the linkedlist
void insertStudent(Student *&head, string sid, string name, Student *&last)
{
    // get new node
    Student *newNode = new Student(sid, name);
    // if list is empty then assign this new node as a head
    if (last == NULL)
    {
        head = newNode;
    }
    // else put this newNode to the last of lastNode
    else
    {
        last->next = newNode;
    }
    // and update lastNode as the lastNode of linkelist
    last = newNode;
}
int main()
{
    // Head of linkedlist
    Student *head;
    // last node is null as initially
    Student *last = NULL;
    // Insert data into the linkedlist
    insertStudent(head, "D1011", "Nicole Kidman", last);
    insertStudent(head, "D1012", "Lea Thompson", last);
    insertStudent(head, "D1013", "Alicia Keys", last);
    insertStudent(head, "D1014", "Lucy Liu", last);
    insertStudent(head, "D1015", "Nancy Smith", last);

    // Read student id
    while (true)
    {

        cout << "Enter the student ID: ";
        string stdID;
        cin >> stdID;
        // keep track on , got desired result or not
        bool isFound = false;
        Student *temp = head;
        // Iterate linkedlist
        while (temp != NULL)
        {
            // if current student id is equal to entered student it
            // then print name of student
            // and break loop
            if (temp->sid == stdID)
            {
                cout << temp->name << endl;
                isFound = true;
                break;
            }
            // go to next node
            temp = temp->next;
        }
        // if student id not found then display error
        if (!isFound)
        {
            cout << "Invalid Entry!" << endl;
        }
        cout << endl;
    }
    return 0;
}