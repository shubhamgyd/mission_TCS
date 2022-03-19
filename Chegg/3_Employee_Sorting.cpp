#include<bits/stdc++.h>
using namespace std;

struct Employee
{
    string name;
    int salary;
    Employee(string str,int val)
    {
        name=str;
        salary=val;
    }
};


// Utility Insertion sort function which sort the employee list according to their salary
void insertionSort(vector<Employee>&data)
{
    int n=data.size();
    for(int i=1;i<n;i++)
    {
        Employee value=data[i]; // c1: Both of this statement executed in (n-1) times
        int key=i;
        while(key>0 && data[key-1].salary>value.salary) //c2: Executing depend on input size of array
        {
            data[key]=data[key-1];
            key=key-1;
        }
        data[key]=value; //c3: Execute in (n-1) time
    } 
}

// So total time complexity T(n)= (n-1)*(c1+c3) +n*(n-1)/2 ==O(n^2)

//For average case, we can assume that T(n) = (c1+c3)*(n-1)+{1+2+3+4+ ... +n-1}*(c2/2)
// We can assume that inner loop will run i/2  times for each i, and not i times. 
//So, 2nd term in expression will be n(n-1)*c2/2 .. Still it will be something like an^2 + bn + c

int main()
{
    // structure , which receive the input data of employees
    vector<Employee>data;
    data.push_back(Employee("Ada",15000));
    data.push_back(Employee("Brian",18000));
    data.push_back(Employee("Carson",12000));
    data.push_back(Employee("Dave",14000));
    data.push_back(Employee("Hary",10000));
    data.push_back(Employee("John",17000));
    data.push_back(Employee("Kris",9000));


    // Employee List before insertion sort
    cout<<"Before Insertion Sort:"<<endl;
    for(auto it:data)
    {
        cout<<it.name<<","<<it.salary<<endl;
    }

    // calling insertiong sort 
    insertionSort(data);

    // Employee List after Insertion sort
    cout<<"\n \nAfter Insertion Sort: "<<endl;
    for(auto it:data)
    {
        cout<<it.name<<","<<it.salary<<endl;
    }
    return 0;
}

// Time complexity:O(n^2)