// Program to find the number of sequences having product less than k

#include<bits/stdc++.h>
using namespace std;

int Count(int arr[],int n,int k,int prod)
{
    if(n==0 && prod<k)
    {
        return 1;
    }
    if(prod>=k)
    {
        return 0;
    }
    else
    {
        int excl=prod;
        int incl=prod*arr[n-1];
        return Count(arr,n-1,k,excl)+Count(arr,n-1,k,incl);
    }
}

// Time Complexity :O(2^n)



// Memoization
int dp[101][101];
int Rec(int arr[],int n,int k,int ind)
{
    if(ind==n)
    {
        return 1;
    }
    if(dp[ind][k]!=-1)
    {
        return dp[ind][k];
    }
    return dp[ind][k]=Rec(arr,n,k,ind+1) + (arr[ind]<k ? Rec(arr,n,k/arr[ind],ind+1):0);
}




// Top Down DP Approach
int table[101][101];
int ProdSubSeq(int arr[],int n,int k,int ind,int prod)
{
    if(ind==n)
    {
        return 0;
    }
    if(table[ind][prod]!=-1)
    {
        return table[ind][prod];
    }
    
    int res=0;
    for(int i=ind;i<n;i++)
    {
        prod*=arr[i];
        if(prod<k)
        {
            res+=1+ProdSubSeq(arr,n,k,i+1,prod);
        }
        prod/=arr[i];
    }
    dp[ind][prod]=res;
    return res;
}

// Time Complexity:O(n*n)
// Space Complexity :O(n*k);


int main()
{
    int arr[]={1,2};
    int k=2;
    // memset(dp,-1,sizeof(dp));
    memset(table,-1,sizeof(table));
    int n=sizeof(arr)/sizeof(arr[0]);
    // cout<<Count(arr,n,k,1)-1<<endl;
    // cout<<Rec(arr,n,k,0)-1<<endl;
    cout<<ProdSubSeq(arr,n,k,0,1)<<endl;
    return 0;
}