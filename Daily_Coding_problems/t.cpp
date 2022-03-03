// #include<bits/stdc++.h>
// using namespace std;

// // Utility Function to take the array input until zero is encountered
// // and return it
// vector<int> Input()
// {
//     // vector is dynamic list to store the elements
//     vector<int>arr;
//     //  we will take input from user until 0 is encountered
//     while(true)
//     {
//         cout<<"Enter element: ";
//         int number;
//         cin>>number;
//         // if input number is 0 then stop to take input
//         if(number==0)
//         {
//             break;
//         }
//         else
//         {
//             arr.push_back(number);                  // else add input number into the list
//         }
//     }

//     // return the list
//     return arr;
// }

// // Utility function , which find the min and max element from the list and print them
// void findMinMax(vector<int>&arr)
// {
//     // mn will keep track on the minimum element from the list
//     int mn=INT_MAX;
//     int n=arr.size();
//     for(int i=0;i<n;i++)
//     {
//         // here we are comparing each element with the previous result
//         mn=min(mn,arr[i]);
//     }

//     //  mx will keep track on the maximum element from the list
//     int mx=INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         // here we are comparing each element with the previous result
//         mx=max(mx,arr[i]);
//     }

//     cout<<"List : ";
//     // printing the list as we taken from the user
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<"\nMinimum element: "<<mn<<endl;
//     cout<<"Maximum element: "<<mx<<endl;
// }

// int main()
// {
//     // here we are taking the input list and storing it
//     vector<int>arr=Input();
//     findMinMax(arr);
//     return 0;
// }

#include <iostream>

using namespace std;

class Student
{

public:
    float cgpa;

    int id;

    string degreeLevel;

    Student *next;
};

Student *createNode(float point, int id)
{

    Student *n = new Student();

    n->cgpa = point;

    n->next = NULL;

    n->id = id;

    return n;
}

void addRecord(float point, Student **head, Student **tail, int id)
{

    Student *n = createNode(point, id);

    if (*head == NULL)

        *head = *tail = n;

    else
    {

        (*tail)->next = n;

        *tail = n;
    }
}

void status(Student *i)
{

    if (i->cgpa >= 3.5)

        i->degreeLevel = "First Class";

    else if (i->cgpa >= 3.0)

        i->degreeLevel = "Second Class Upper";

    else

        i->degreeLevel = "Second Class Lower";
}

void display(Student *i)
{

    while (i != NULL)
    {

        cout << "ID: " << i->id << endl;

        cout << "CGPA:" << i->cgpa << endl;

        cout << "Status: " << i->degreeLevel << endl;

        i = i->next;
    }
}

float average(Student *i)
{

    float total = 0, cou = 0;

    while (i != NULL)
    {

        total += i->cgpa;

        cou++;

        i = i->next;
    }

    return total / cou;
}

void deanlist(Student *i)
{

    int cou = 0;

    while (i != NULL)
    {

        if (i->cgpa >= 3.5)
        {

            cout << i->cgpa << " ";

            cou++;
        }

        i = i->next;
    }

    cout << cou << endl;
}

int main()
{

    float point;

    char choice;

    int id;

    Student *head = NULL;

    Student *tail = NULL;

    do
    {

        cout << "Enter ID: ";

        cin >> id;

        cout << "Enter CGPA point: ";

        cin >> point;

        addRecord(point, &head, &tail, id);

        cout << "Enter [Y] to add another record: ";

        cin >> choice;

    } while (choice == 'Y');

    cout << "List of existing records " << endl;

    display(head);

    cout << "\nAverage value of CGPA records: ";

    cout << average(head) << endl;

    cout << "List of CGPA points under Dean List: ";

    deanlist(head);

    return 0;
}