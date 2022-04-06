#include<iostream>
using namespace std;

int main()
{
    // loop will print the pattern
    for(int i=1;i<=4;i++)
    {
        // this loop will print * line by line
        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }
        // new line
        cout<<endl;
    }
    return 0;
}