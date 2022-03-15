#include<iostream>
using namespace std;

void swap_three(int*, int*,int*);

int main()
{

    // write your code here

    cout<<"Enter three numbers: "<<endl;
    // three numbers input taken by the user
    int p1,p2,p3;
    cout<<"var1: ";
    cin>>p1;
    cout<<"var2: ";
    cin>>p2;
    cout<<"var3: ";
    cin>>p3;

    // Number before swapping
    cout<<"\nNumbers before swapping: "<<endl;
    cout<<"var1: "<<p1<<", var2:"<<p2<<", var3:"<<p3<<endl;

    

    // Utility function , which will swaps three numbers
    // Here we are passing the numbers by reference
    // means we are passing the memory addresses of values
    swap_three(&p1,&p2,&p3);
    
    // Numbers after swapping
    cout<<"\nNumbers after swapping: "<<endl;
    cout<<"var1: "<<p1<<", var2:"<<p2<<", var3:"<<p3<<endl;
}


// Utility function which swaps the numbes
// This function takes the parameters in the memory referece
void swap_three(int* p1,int* p2,int *p3)
{
    // write your code here

    // here we are swapping the first and second number
    int temp=*p2;
    *p2=*p1;
    *p1=temp;


    // Here we are swapping the first and third number
    temp=*p1;
    *p1=*p3;
    *p3=temp;
}