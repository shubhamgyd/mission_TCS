#include <iostream>
using namespace std;
// Structure which represent the linked list
struct nodeType
{
    char letter;
    nodeType *link;
};

int main()
{
    // Input of sequence of letter which is ending with letter 9
    cout << "Enter a sequence of letters ending with number 9(e.g 9, 19,29 . so on) : ";
    string sequence;
    cin >> sequence;

    // checking if given sequence is ending with 9 or not
    bool isEndingWithNine = false;
    // condition false
    // take the input until is valid
    if (sequence[sequence.length() - 1] != '9')
    {
        isEndingWithNine = true;
        while (isEndingWithNine)
        {
            cout << "Please enter correct sequence of numbers: ";
            cin >> sequence;
            if (sequence[sequence.length() - 1] != '9')
            {
                isEndingWithNine = true;
            }
            else
            {
                isEndingWithNine = false;
            }
        }
    }

    // Head pointing to the first node of sequence of letters
    nodeType *head;
    nodeType *last = NULL;
    int length = sequence.length();  // length of sequence
    for (int i = 0; i < length; i++)
    {
        char letter = sequence[i];
        // allocating the memory to current node
        struct nodeType *newNode = (struct nodeType *)malloc(sizeof(struct nodeType));
        // setting data with current letter
        newNode->letter = letter;

        // set next pointer as null means ending
        newNode->link = NULL;


        // now increase the head list just by increamenting the lastnode link
        if (last == NULL)
        {
            head = newNode;
        }
        else
        {
            last->link = newNode;
        }
        last = newNode;
    }
    // Printing the linked list
    nodeType* curr=head;
    while(curr)
    {
        cout<<curr->letter<<"->";
        curr=curr->link;
    }
    cout<<"NULL"<<endl;

    // searching in linked list
    bool search=true;
    while(search)
    {
        // User input to search a letter in list
        cout<<"Enter letter to search in linked list(e.g 1,2,3 so on: ";
        char userLetter;
        cin>>userLetter;
        nodeType* temp=head;
        bool isFound=false;

        // Traverse linke list to search a entered letter
        while(temp!=NULL)
        {
            // if letter if cound in linked list
            if(temp->letter==userLetter)
            {
                // print found 
                // set isFound true
                cout<<"Found !!!"<<endl;
                isFound=true;
                break;
            }
            // else move to the next link
            temp=temp->link;
        }

        // of not found in entire list
        // then print not found
        if(isFound==false)
        {
            cout<<"Not Found!!"<<endl;
        }

        // continuing with search or not
        cout<<"Do you want to continue search(Y|N): "<<endl;
        char ch;
        cin>>ch;
        if(ch=='Y')
        {
            search=true;
        }
        else
        {
            search=false;
        }
    }
}