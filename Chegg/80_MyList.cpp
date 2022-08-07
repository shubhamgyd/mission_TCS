#include<iostream>
using namespace std;

int main()
{
    // List of 10 double numbers
    double myList[10];
    // insert 4.5 at 0th position
    myList[0]=4.5;
    // Itearte from 1 to 9
    for(int i=1;i<10;i++)
    {
        // take pervious element and multiply it by current index
        myList[i]=i*myList[i-1];
        //  if index is greater than 3
        if(i>3)
        {
            // divide the current index element by 2
            myList[i]=myList[i]/2;
        }
    }
    cout<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<myList[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    return 0;
}