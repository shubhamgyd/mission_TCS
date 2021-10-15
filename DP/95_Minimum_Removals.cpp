/*
Given N integers and K, find the minimum number of elements that should be removed, 
such that Amax-Amin<=K. After the removal of elements, Amax and Amin is considered 
among the remaining elements. 

Examples: 

Input : a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20} 
          k = 4 
Output : 5 
*/
#include<bits/stdc++.h>
using namespace std;

int dp[501][501];
int Removals(int arr[],int i,int j,int k)
{
    //base case;
    if(i>=j)
    {
        return 0;
    }

    else if(arr[j]-arr[i]<=k)
    {
        return 0;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    else if(arr[j]-arr[i]>k)
    {
        dp[i][j]=1+min(Removals(arr,i+1,j,k),Removals(arr,i,j-1,k));
    }
    return dp[i][j];
}
// Time complexity:O(n*n)
// Space Complexity:O(n*n);



// Optimised Solution by using binary search

int Ind(int key,int i,int n,int arr[],int k)
{
    int ans=-1;
    int low=i+1;
    int high=n-1;
    while(low<high)
    {
        int  mid=low+(high-low)/2;
        if(arr[mid]-key<=k)
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}


int Removals1(int arr[],int n,int k)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    int count=0;
    int ans=n-1;
    for(int i=0;i<n;i++)
    {
        count=Ind(arr[i],i,n,arr,k);
        if(count!=-1)
        {
            ans=min(ans,n-(count-i+1));
        }
    }
    return ans;
}
// Time complexity: O(nlogn)
// Space Complexity: O(n)



// Further Optimise 
// Dp Solution



int main()
{
    memset(dp,-1,sizeof(dp));
    int arr[]={-10,1,0,-10,7};
    int k=8;
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    // cout<<Removals(arr,0,n-1,k)<<endl;
    cout<<Removals1(arr,n,k)<<endl;
}