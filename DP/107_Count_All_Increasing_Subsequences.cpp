#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    unsigned long long int countSub(int arr[], int n)
    {
        //Your code goes here
         int cSub[n];

    /* Initialize cSub values for all indexes */
    for (int i = 0; i < n; i++ )
        cSub[i] = 1;


    for (int i = 1; i < n; i++ )
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j])
                cSub[i] += cSub[j];

    unsigned long long int result = 0;
    for (int i = 0; i < n; i++ )
          result += cSub[i];

    return result;
    }
};
// Time Complexity :O(n*n)
// Space Complexity :O(1)









// Optimise DP
int ways(int arr[],int n)
{
    // because 0-9
    int dp[10]={0};
    // for(int i=0;i<10;i++)
    // {
    //     dp[i]=1;
    // }

    for(int i=0;i<n;i++)
    {
        for(int j=arr[i]-1;j>=0;j--)
        {
            dp[arr[i]]+=dp[j];
        }
        dp[arr[i]]++;
    }
    int res=0;
    for(int i=0;i<10;i++)
    {
        res+=dp[i];
    }
    return res;
}
// Time Complexity :O(n)
// Coz inner loop run only 10 times
// Space Complexity :O(1)

int main()
{
    int arr[]={2,4,1,5,3,6,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    cout<<obj.countSub(arr,n)<<endl;
    cout<<ways(arr,n)<<endl;
    return 0;
}