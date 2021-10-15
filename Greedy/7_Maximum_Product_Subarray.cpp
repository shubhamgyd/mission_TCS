// To find the maximum product subarray

#include<bits/stdc++.h>
using namespace std;

int MaxSubarrayProd(int arr[],int n)
{
    int prod=1;
    int zr=0;
    int neg=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            neg++;
        }
        else if(arr[i]==0)
        {
            zr++;
        }
        if(arr[i]!=0)
        {
            prod*=arr[i];
        }
    }

    // Exception handle
    if( zr==n-1 && neg==1)
    {
        return 0;
    }

    // Handle for odd number of negative digits
    if(neg%2)
    {
        int ln=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0) 
            {
                ln=max(ln,arr[i]);
            }
            prod/=ln;
        }
    }

    return prod;
    
}

int main()
{
    int arr[]={ -1, -1, -2, 4, 3 };
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<MaxSubarrayProd(arr,n);
    return 0;
}