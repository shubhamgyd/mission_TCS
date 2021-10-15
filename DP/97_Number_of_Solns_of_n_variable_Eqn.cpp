#include<bits/stdc++.h>
using namespace std;


int Count(int arr[],int i,int j,int rhs)
{
    if(rhs==0)
    {
        return 1;
    }
    int res=0;
    for(int k=i;k<=j;k++)
    {
        if(arr[k]<=rhs)
        {
            res+=Count(arr,k,j,rhs-arr[k]);
        }
    }
    return res;
}
// Time Complexity :Exponential


int main()
{
    int arr[]={2,2,5};
    int rhs=4;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<Count(arr,0,n-1,rhs)<<endl;
    return 0;
}