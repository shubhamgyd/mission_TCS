/*
Problem Statement
You are given an array of distinct numbers ‘arr’. Your task is to return the largest subset of numbers from ‘arr’, such that any pair of numbers ‘a’ and ‘b’ from the subset satisfies the following: a % b == 0 or b % a == 0.
For Example:
You are given ‘arr’ = [1, 16, 7, 8, 4] as you can the set {1, 4, 8, 16}, here you can take any pair from the set and either one of the elements from the pair will divide the other.
Input Format:
The first line of input contains a single integer ‘T’ representing the number of test cases.

The first line of each test case contains a single integer ‘N’ representing the number of elements in the array.

The second line of each test case contains ‘N’ space-separated integers representing the elements of the array.
Output Format:
For each test case, print all set elements in a space-separated manner.

Print a separate line for each test case.
Constraints:
1 <= T <= 10
1 <= N <= 10^3
0 <= arr[i] <= 10^8    

Time Limit: 1 sec
Note :
You do not need to print anything. It has already been taken care of. Just implement the given function. 
Sample Input 1:
2
5
1 16 7 8 4
3
1 2 5
Sample Output 1 :
 1 4 8 16
 1 2
*/
// Basically we have to find the longest increasing subsequence
// in which all elements are divisible by it's pervious elemtns


#include<bits/stdc++.h>
using namespace std;

vector<int> divisibleSet(vector<int> &arr){
    // Write your code here.
    sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<int>ans;
    vector<int>hash(n,0);
    vector<int>dp(n,1);
    for(int i=0;i<n;i++)
    {
        hash[i]=i;
        for(int j=0;j<i;j++)
        {
            if(arr[i]%arr[j]==0 and dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
        }
    }
    int mx=0;
    int ind=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]>mx)
        {
            mx=dp[i];
            ind=i;
        }
    }
    ans.push_back(arr[ind]);
    while(hash[ind]!=ind)
    {
        ind=hash[ind];
        ans.push_back(arr[ind]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
    
}