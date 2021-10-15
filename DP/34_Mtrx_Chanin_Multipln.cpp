// Matrix Chain Multiplication 
// Basically we have to find out the minimum number of multiplication to make the matrix chain


#include<bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
int MCM(int arr[],int i,int j)
{
    //This is the base condition of gievn que ..mean if the given array have only one element
    // it must have greater than one element  in the givn array
    if(i>=j) return 0;
    int mn=INT_MAX;
    // Here we are traversing the int k between i and j and at the same time we are checking 
    // the matrix chain multiplication , if the multiplication value is minimum then , we are updating 
    // it var ...and check it for next multiplication and so on.
    for(int k=i;k<j;k++)
    {
        int temp=MCM(arr,i,k) + MCM(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        if(temp<mn)
        {
            mn=temp;
        }
    }
    // Returning the minimum number of multiplication
    return mn;
}

int main()
{
    // Format
    // Either string or array
    // we have to find out the left side index and right side index 
    int arr[]={4,11,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=1;
    int j=n-1;
    cout<<"Minimum number of Multiplication is: "<<MCM(arr,i,j)<<'\n';
    return 0;
    
}