#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        
        if (n <= 2)
            return 1;

        vector<int> maxArr(n+1, 0);
                    
        /** For a number i: write i as a sum of integers, then take the product of those integers.
        maxArr[i] = maximum of all the possible products */
        
        maxArr[1] = 0;
        maxArr[2] = 1; // 2=1+1 so maxArr[2] = 1*1
        
        for (int i=3; i<=n; i++) {
            for (int j=1; j<i; j++) {
                /** Try to write i as: i = j + S where S=i-j corresponds to either one number or a sum of two or more numbers
                
                Assuming that j+S corresponds to the optimal solution for maxArr[i], we have two cases:
                (1) i is the sum of two numbers, i.e. S=i-j is one number, and so maxArr[i]=j*(i-j)
                (2) i is the sum of at least three numbers, i.e. S=i-j is a sum of at least 2 numbers,
                and so the product of the numbers in this sum for S is maxArr[i-j]
                (=maximum product after breaking up i-j into a sum of at least two integers):
                maxArr[i] = j*maxArr[i-j]
                */
                maxArr[i] = max(maxArr[i], max(j*(i-j), j*maxArr[i-j]));
            }
        }
        return maxArr[n];
    }
};

// int dp[10001][10001];
int solve(int n,int k,vector<vector<int>>&dp)
{
    if(k>=n or n<2*k)
    {
        return dp[n][k]=-1;
    }

    if(dp[n][k]!=-2)
    {
        return dp[n][k];
    }

    int ans=-1;
    int low=k;
    int high=n;
    while(low<=high)
    {
        ans=max(ans,low*(n-low));
        int temp=solve(n-low,k,dp);
        if(temp!=-1)
        {
            ans=max(ans,temp*low);
        }
        low++;
    }
    return dp[n][k]=ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    // memset(dp,-1,sizeof(dp));
    vector<vector<int>>dp(10001,vector<int>(10001,-2));
    int total1=solve(n,k,dp);
    cout<<total1<<endl;
    return 0;
}