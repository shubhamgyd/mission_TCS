#include<iostream>
using namespace std;


// Utility function which add an Item into list
void addItem(string *list,int n)
{
    cout<<"Enter student name: ";
    string name;
    cin>>name;
    for(int i=0;i<n;i++)
    {
        // if we found the empty space at index i
        // add item into that index and stop 
        if(list[i].empty())
        {
            list[i]=name;
            break;
        }
    }

    // display message an item added successfully
    cout<<"Item added successfully...!!!"<<endl;
}



// Utility function which display list items
void displayList(string *list,int n)
{
    cout<<"Student Names: "<<endl;
    for(int i=0;i<n;i++)
    {
        if(!list[i].empty())
        {
            cout<<list[i]<<", ";
        }
    }
    cout<<endl;
}


// Utility function which delete an Item from list
void deleteItem(string *list, int n,int &items)
{
    cout<<"Enter student name: ";
    string name;
    cin>>name;

    // it will keep track on, an item deleted or not
    int deleted=0;
    for(int i=0;i<n;i++)
    {
        // if target is not equal to current index name, then continue
        if(list[i]!=name && !deleted)
        {
            continue;
        }

        // if target is not equal to current index name but we have deleted our target from list
        // then we need to swap the previous empty space with the current list name
        else if(list[i]!=name && deleted)
        {
            list[i-1]=list[i];
            list[i]="";
        }
        
        // we have found the target, just replace current index with empty space
        else if(list[i]==name)
        {
            // mark we have deleted target
            deleted=1;
            list[i]="";
        }
    }

    // if we have deleted student from list
    if(deleted==1)
    {
        cout<<"Item deleted successfully...!!"<<endl;

        // reduce size of list by 1
        items--;
    }

    // else show error message
    else
    {
        cout<<"Item not found in list...!!!"<<endl;
    }
}



// sorted list items using Insertion sort algorithm
void sortedDisplay(string *list,int n)
{
    string newList[n];
    int j=0;
    for(int i=0;i<n;i++)
    {
        newList[i]=list[i];
    }

    for(int i=1;i<n;i++)
    {
        string value=newList[i]; // c1: Both of this statement executed in (n-1) times
        int key=i;
        while(key>0 && newList[key-1]>value) //c2: Executing depend on input size of array
        {
            newList[key]=newList[key-1];
            key=key-1;
        }
        newList[key]=value; //c3: Execute in (n-1) time
    } 

    // Display sorted data
    cout<<"Sorted names of students: "<<endl;
    for(int i=0;i<n;i++)
    {
        if(!newList[i].empty())
        {
            cout<<newList[i]<<", ";
        }
    }
}


int main()
{
    cout<<"\nEnter number of students to add into list: ";
    // number of students
    int n;
    cin>>n;

    // to store student names
    string list[n];

    // keep track on number of students in list
    int items=0;
    int choice;
    do
    {
        cout<<"\n                   MENU               "<<endl;
        cout<<"1. Add an Item to List"<<endl;
        cout<<"2. Delete an Item from List"<<endl;
        cout<<"3. Display the whole List"<<endl;
        cout<<"4. Display the Whole List Sorted"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        cout<<endl;
        
        // if choise ==1
        if(choice==1)
        {
            // if there is space in list
            if(items<n)
            {
                addItem(list,n);
                items++;
            }

            // else show error message
            else
            {
                cout<<"List is full, you can't add more items!"<<endl;
            }
        }

        // if choice==2
        else if(choice==2)
        {
            // if there are items in list
            if(items>0)
            {
                deleteItem(list,n,items);
            }
            // else show error message
            else
            {
                cout<<"List is empty..!!"<<endl;
            }
        }

        // if choice==3
        else if(choice==3)
        {
            // if list have items
            if(items>0) displayList(list,n);

            // else show error message
            else
            {
                cout<<"List is empty..!!"<<endl;
            }
        }

        // if choice==4
        else if(choice==4)
        {
            // if list have items
            if(items>0)
            {
                sortedDisplay(list,n);
            }
            // else show error message
            else
            {
                cout<<"List is empty..!!"<<endl;
            }
        }

        // exit from program
        else if(choice==5)
        {
            cout<<"Exiting the program..!!"<<endl;
            exit(0);
        }
        else
        {
            cout<<"Enter correct choice..!!!"<<endl;
            
        }


    }while(choice>=1 && choice<=5);
    return 0;
}