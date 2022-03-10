// count of subsets of given sum

#include<bits/stdc++.h>
using namespace std;

int countSubSet(vector<int>&res,int target,int n)
{
    if(target==0)
    {
            return 1;
    }
    if(n==0)
    {
        return res[n]==target;
    }

    int noPick=countSubSet(res,target,n-1);
    int pick=0;
    if(res[n]<=target)
    {
        pick=countSubSet(res,target-res[n],n);
    }
    return pick+noPick;
}
// Time Complexity:Exponential
// Auxilary Space: O(1)


// Memoization
int dp[10001][10001];
int countSubsets(vector<int>&res,int target,int n)
{
    if(target==0)
    {
            return 1;
    }
    if(n==0)
    {
        return res[n]==target;
    }
    if(dp[n][target]!=-1)
    {
        return dp[n][target];
    }
    int noPick=countSubsets(res,target,n-1);
    int pick=0;
    if(res[n]<=target)
    {
        pick=countSubsets(res,target-res[n],n);
    }
    return dp[n][target]= pick+noPick;
}
// Time Complexity:O(N*sum)
// Auxilary Complexity:O(n*sum)




// Tabulation method
int countSubSets1(vector<int>&res,int target,int n)
{
    int dp1[n+1][target+1];
    for(int i=0;i<=n;i++){
        dp1[i][0]=1;
    }
    for(int j=1;j<=target;j++)
    {
        dp1[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            if(res[i-1]<=target)
            {
                dp1[i][j]=dp1[i-1][j]+dp1[i-1][j-res[i-1]];
            }
            else
            {
                dp1[i][j]=dp1[i-1][j];
            }
        }
    }
    return dp1[n][target];
}
// Time Complexity:O(n*sum)
// Space Complexity:O(n*sum)





// Space optimize
int Space(vector<int>&res,int target,int n)
{
    vector<int>prev(target+1,0),curr(target+1,0);
    prev[0]=curr[0]=1;
    if(res[0]<=target) prev[res[0]]=1;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            int nonTake=prev[j];
            int take=0;
            if(res[i]<=j) take=prev[j-res[i]];
            curr[j]=nonTake+take;
        }
        prev=curr;
    }
    return prev[target];
}
// Time Complexity:O(n*sum)
// Space Complexity:O(sum)

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int target;
    cin>>target;
    cout<<countSubSet(res,target,n-1)<<endl;
    cout<<countSubsets(res,target,n-1)<<endl;
    cout<<countSubSets1(res,target,n)<<endl;
    cout<<Space(res,target,n)<<endl;
    return 0;
}