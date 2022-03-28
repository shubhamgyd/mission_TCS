#include<iostream>
#include<map>
using namespace std;


int main()
{
    // Maps are associative containers that store elements in a mapped fashion. 
    // Each element has a key value and a mapped value. No two mapped values can have the 
    // same key values.


    // In future if we want to delete or modify the names, then we can also do them
    // map support this features
    map<string,string>names;
    // initially insert some names randomly
    names["Jones"]="Jones";
    names["Smith"]="Smith";
    names["Duggan"]="Duggan";
    names["Alpha"]="Alpha";

    cout<<"\nInitial Sorted list of names: "<<endl;
    for(auto it:names)
    {
        // here we have stored the names in first part 
        // means now the container contains name(it.first) -> name(it.second)
        cout<<it.first<<", ";
    }
    cout<<endl;
    cout<<"\nEnter some names for testing purpose: "<<endl;
    // for testing purpose add some names into list to check, either list is automatically sorted or not till the end of list
    for(int i=0;i<5;i++)
    {
        // take input from user
        cout<<"Enter name: ";
        string name;
        cin>>name;

        // append to the set of names
        // it automatically sort the names 
        names[name]=name;

        // print the sorted list of names
        cout<<"\nNew sorted list of names: ";
        for(auto it:names)
        {
            cout<<it.first<<", ";
        }
        cout<<endl;
    }
    return 0;
}
