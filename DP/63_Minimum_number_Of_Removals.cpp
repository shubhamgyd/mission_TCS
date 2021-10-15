// In this program we are going to find the minimum number of removals i.e max-min<=k

#include<bits/stdc++.h>
using namespace std;

int Removals(int arr[],int n,int k)
{
    sort(arr,arr+n);
    int dp[n];
    memset(dp,-1,sizeof(dp));
    // as dp[0] = 0 (base case) so min
  // no of elements to be removed are
  // n-1 elements
    int ans=n-1;        // Maximum Removals
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        dp[i]=i;
        int j=dp[i-1];
        while(j!=i && arr[i]-arr[j]>k)
        {
            j++;
        }
        dp[i]=min(dp[i],j);
        ans=min(ans,(n-(i-j+1)));       // window size;
    }
    return ans;
}

// Time Complexity : O(logn)
// Space: O(n)

int main()
{
    int arr[]={1,3,4,9,10,11,12,17,20};
    int k=4;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Total Removals are: "<<Removals(arr,n,k)<<endl;
    return 0;
}