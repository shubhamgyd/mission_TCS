/*
Relative sorting is defined as sorting two arrays (both in strictly ascending order) 
such that the only operation allowed is swapping i'th element of one array with the i'th 
elementh of the other array
An array is said to be in strictly ascending order if i'th element of the array is smaller 
than (i+1)'th element of the array.
You are given two arrays of size N. print the minimum number of swaps required to make both
 arrays relatively sorted.

Note:
If the arrays are already relatively sorted, then print '0'
If the arrays cannot be relatively sorted, then print '-1'.
Input Format:
The input consist of 3 lines:

First line consist of the size of each array, i.e. N
The next two lines contain N elements each seperated by a space
Output Format:
The output will be an integer i.e., the minimum number of swaps required to make both 
arrays relatively sorted.

Constraints:
0 < N < 11000
0 < Elements in array <= 10^9
Example 1:

Input:
4
1 4 4 9
2 3 5 10

Output: 1
Explanation: To make both arrays strictly increasing we can swap 4 and 3 or 4 and 5.
*/

#include<bits/stdc++.h>
using namespace std;


int solve(int i,bool swapped,int n,vector<int>&A,vector<int>&B)
{
    // base case
    if(i==n) return 0;
    int num1=A[i-1];
    int num2=B[i-1];

    // if last pair is swapped
    if(swapped)
    {
        swap(num1,num2);
    }
    int ans=INT_MAX;
    // If condision satisfied
    // last pair of elements are smaller than current one
    // choice 1 we don't swap if it is in increasing
    if(A[i]>num1 and B[i]>num2)
    {
        ans=solve(i+1,0,n,A,B);
    }

    // if last pelement of A is smaller than the B[i] and 
    // last element of B is smaller than A[i]
    // Then do swap
    // choice 2 we swap if swapping result in increasing order
    if(A[i]>num2 and B[i]>num1)
    {
        ans=min(ans,solve(i+1,1,n,A,B)+1);
    }
    return ans;
}
// T:O(Exponential)
// S:O(n) stack space recursion




// Memoization Code
int Memo(int i,int swapped,int n,vector<int>&A,vector<int>&B,vector<vector<int>>&dp)
{
    if(i==n) return 0;
    if(dp[i][swapped]!=-1) return dp[i][swapped];
    int num1=A[i-1];
    int num2=B[i-1];

    // if last pair is swapped
    if(swapped)
    {
        swap(num1,num2);
    }
    int ans=INT_MAX;
    // If condision satisfied
    // last pair of elements are smaller than current one
    // choice 1 we don't swap if it is in increasing
    if(A[i]>num1 and B[i]>num2)
    {
        ans=Memo(i+1,0,n,A,B,dp);
    }

    // if last pelement of A is smaller than the B[i] and 
    // last element of B is smaller than A[i]
    // Then do swap
    // choice 2 we swap if swapping result in increasing order
    if(A[i]>num2 and B[i]>num1)
    {
        ans=min(ans,Memo(i+1,1,n,A,B,dp)+1);
    }
    return dp[i][swapped]=ans;
}

int main()
{
    int n;
    cin>>n;
    int A[n];
    int B[n];
    vector<int>nums1,a,b;
    vector<int>nums2;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        nums1.push_back(A[i]);
        a.push_back(A[i]);
    }
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
        nums2.push_back(B[i]);
        b.push_back(B[i]);
    }
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    int ans=solve(1,0,n,nums1,nums2);
    cout<<ans<<endl;
    vector<vector<int>>dp(n+1,vector<int>(2,-1));
    int ans1=Memo(1,0,n,nums1,nums2,dp);
    



    // Tabulation Method
    int len=a.size();
    int notSwapped[1000]={0};
    int swapped[1000]={1};
    for(int i=1;i<len;i++)
    {
        notSwapped[i]=swapped[i]=len;
        if(a[i]>a[i-1] and b[i]>b[i-1])
        {
            swapped[i]=swapped[i-1]+1;
            notSwapped[i]=notSwapped[i-1]+1;
        }
        if(a[i-1]<b[i] and b[i-1]<a[i])
        {
            swapped[i]=min(swapped[i],notSwapped[i-1]+1);
            notSwapped[i]=min(notSwapped[i],swapped[i-1]);
        }
    }
    cout<<min(swapped[len-1],notSwapped[len-1])<<endl;
    // T:O(n)
    // S:O(n)
}