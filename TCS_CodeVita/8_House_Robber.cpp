/*
There are n houses build in a line, each of which contains some value in it.

 A thief is going to steal the maximal value of these houses, but he can’t steal in 
 two adjacent houses because the owner of the stolen houses will tell his two neighbours 
 left and right side.

What is the maximum stolen value?

Sample Input: val[] = {6, 7, 1, 3, 8, 2, 5}
*/
#include<bits/stdc++.h>
using namespace std;

int Rob(vector<int>&res)
{
    int n=res.size();
    int a=res[0];
    int b=max(res[0],res[1]);
    int c;
    for(int i=2;i<n;i++)
    {
        c=max(b,a+res[i]);
        a=b;
        b=c;
    }
    return c;
}
// Time Complexity:O(n)
// Space Complxity:O(1)

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int dp[n+1];
    dp[1]=res[0];
    dp[2]=max(res[0],res[1]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+res[i-1]);
    }
    cout<<"Maximum value can robber can rob is: "<<dp[n]<<endl;
    cout<<"Maximum value can robber can rob is: "<<Rob(res)<<endl;
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(n)