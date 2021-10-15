// Mcm ..in this code we are using the matrix to store the values 
// Rest of the code is remains same only few things are changed ....we will discuss here

#include<bits/stdc++.h>
using namespace std;

// global declaration of matric so that we can edit it after the need
int  dp[100][100];

int MCM(int arr[],int i,int j)
{
    if(i>=j) return 0;

    //Here we are checkinng ..if the given block is previously filled or not ..if it is filled then we 
    // reeturn this block value
    if(dp[i][j]!=-1) return dp[i][j];
    int mn=INT_MAX;

    // same as previous 
    for(int k=i;k<j;k++)
    {
        int temp=MCM(arr,i,k)+MCM(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        mn=min(mn,temp);
    }
    // here before returining , we assigned it and then return it.
    return dp[i][j]=mn;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int arr[]={100,250,1000};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=1;
    int j=n-1;
    cout<<"Minimum Matrix Multiplication is: "<<MCM(arr,i,j)<<'\n';
    return 0;
}