/*
Problem Statement
Given an integer array ‘ARR’ of length ‘N’, return the number of longest increasing subsequences in it.
The longest increasing subsequence(LIS) is the longest subsequence of the given sequence such that all elements of the subsequence are in increasing order.
Note :
The subsequence should be a strictly increasing sequence.
For Example :
Let ‘ARR’ = [50, 3, 90, 60, 80].
In this array the longest increasing subsequences are [50, 60, 80] and [3, 60, 80]. There are other increasing subsequences as well but we need the number of longest ones. Hence the answer is 2.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases, then each test case follows:

The first line of each test case contains a single integer ‘N’ denoting the length of the array ‘ARR’.

The following line contains N space-separated integers representing elements in ‘ARR’.
Output Format :
For each test case, find the number of longest increasing subsequences.

Output for each test case will be printed on a separate line.
Note :
You are not required to print anything; it has already been taken care of. Just implement the function.
Constraints :
1 ≤ T ≤ 10      
1 ≤ N ≤ 2000
1 ≤ ARR[i] ≤ 10 ^ 6

Time limit: 1 sec
Sample Input 1 :
2
5
50 3 90 60 80
4
3 7 4 6
Sample Output 1 :
2
1
Explanation For Sample Input 1 :
For test case 1 :
The length of LIS is 3 and there are two such LIS, which are[50, 60, 80] and [3, 60, 80].

For test case 2 :
The length of LIS is 3 and there is only one such LIS, which is [3, 4, 6].
*/


#include<bits/stdc++.h>
using namespace std;


int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    vector<int>dp(n,1);
    vector<int>count(n,1);
    int mx=0;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i] and dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
                count[i]=count[j];
            }
            
            // if same length.. increase count
            else if(arr[j]<arr[i] and dp[j]+1==dp[i])
            {
                count[i]+=count[j];
            }
        }
        mx=max(mx,dp[i]);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==mx) cnt+=count[i];
    }
    return cnt;
    
}