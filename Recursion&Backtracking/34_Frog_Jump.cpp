/*
There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. 
HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in 
the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either 
to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog 
to reach from 1st stair to Nth stair.
For Example
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 
2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10
 energy lost). So, the total energy lost is 20.
Input Format:
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains a single integer,' N’, denoting the number of stairs in
 the staircase,

The next line contains ‘HEIGHT’ array.
Output Format:
For each test case, return an integer corresponding to the minimum energy lost to reach the last stair.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 100000.
1 <= HEIGHTS[i] <= 1000 .

Time limit: 1 sec
Sample Input 1:
2
4

10 20 30 10
3
10 50 10
Sample Output 1:
20
0
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>&heights)
{
    if(n==0)
    {
        return 0;
    }
    int left=solve(n-1,heights)+abs(heights[n]-heights[n-1]);
    int right=INT_MAX;
    if(n>1)
    {
        right=solve(n-2,heights)+abs(heights[n]-heights[n-2]);
    }
    return min(left,right);
}
// Time Complexity:O(2^n)
// Space Complexity:O(1)


int solve1(vector<int>&heights,int n,vector<int>&dp)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int left=solve1(heights,n-1,dp)+abs(heights[n]-heights[n-1]);
    int right=INT_MAX;
    if(n>1)
    {
        right=solve1(heights,n-2,dp)+abs(heights[n]-heights[n-2]);
    }
    return dp[n]=min(left,right);
}
// Time Complexity:O(n)
// Space Complexity:O(n)

int Memoization(vector<int>&heights,int n)
{
    vector<int>dp(n+1,-1);
    return solve1(heights,n-1,dp);
}





// Space Optimization
int OptimizeDP(vector<int>&heights,int n)
{
    int prev=0;  // will keep track on the previous energy
    int prev2=0; // will keep track on the second previous energy

    for(int i=1;i<n;i++)
    {
        int left=prev+abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1)
        {
            right=prev2+abs(heights[i]-heights[i-2]);
        }
        int res=min(left,right);
        prev2=prev;
        prev=res;
    }
    return prev;
}
// Time Complexity:O(n)
// Space Complexity:O(1)




int main()
{
    int n;
    cin>>n;
    vector<int>heights(n);
    for(int i=0;i<n;i++)
    {
        cin>>heights[i];
    }
    cout<<solve(n-1,heights)<<endl;
    cout<<Memoization(heights,n)<<endl;
    cout<<OptimizeDP(heights,n)<<endl;
    return 0;
}
