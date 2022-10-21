/*
Description
Given a sequence of integers, find the longest increasing subsequence (LIS).

You code should return the length of the LIS.

What's the definition of longest increasing subsequence?

The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.

https://en.wikipedia.org/wiki/Longest_increasing_subsequence

Example
Example 1:

Input:

nums = [5,4,1,2,3]
Output:

3
Explanation:

LIS is [1,2,3]
Example 2:

Input:

nums = [4,2,4,5,3,7]
Output:

4
Explanation:

LIS is [2,4,5,7]

Challenge
Time complexity O(n^2)O(n 
2
 ) or O(nlogn)O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;




/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
    We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
    an element before arr[n-1] max_ref is
    used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int LIS(vector<int>&res,int n,int &temp,vector<int>&dp)
{   
    if(n==1) return dp[n]=1;


    // if(dp[n]!=-1) return dp[n];
    int cnt;
    int mx=1;



    /* Recursively get all LIS ending with arr[0],
    arr[1] ... arr[n-2]. If arr[i-1] is smaller
    than arr[n-1], and max ending with arr[n-1]
    needs to be updated, then update it */
    for(int i=1;i<n;i++)
    {
        cnt=LIS(res,i,temp,dp);
        if(res[i-1]<res[n-1] and cnt+1>mx)
        {
            mx=cnt+1;
        }
    }

    // compre it with the final result and update the value
    if(mx>temp)
    {
        temp=mx;
    }
    return mx;

}


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }

    // solition 1: Recursion
    vector<int>dp(n,-1);
    int temp=1;
    int ans=LIS(res,n,temp,dp);
    cout<<temp<<endl;


    // Solution 2: Tabulation

    int table[n];
    table[0]=1;
    for(int i=1;i<n;i++)
    {
        table[i]=1;    // if single element
        
        // check if every jth element is smaller than ith element or not
        // if ith element is greater than the jth element then increase the 
        // LIS at ith index
        for(int j=0;j<i;j++)
        {
            if(res[j]<res[i] and table[j]+1>table[i])
            {
                table[i]=table[j]+1;
            }
        }
    }
    // find the length of LIS is end at ith index
    int mx_length=*max_element(table,table+n);
    cout<<mx_length<<endl;
    // Time Complexity:O(n*n)
    // Space Complexity:O(n);




    // Solution 3: nlogn method ( using STL)
    set<int>st;    // it will trak on the number of elemetns

    // iterate the array of elements
    for(auto it:res)
    {
        // if number is already present in the set
        if (st.find(it) != st.end()) continue;

        st.insert(it);

        // now find it's upper bound
        auto ele=st.upper_bound(it);

        // if the upper bound of inserted element is in between the 
        // end and start of array..means set have already maximum element in it 
        // so this number would not give us the maximum LIS
        // erase it      



        // but incase if the upper bound of the element is at the end of the set mean... till that
        // index none other element is greater than this elemtns, so leve it as it is and move to
        // the next element
        if(ele!=st.end())
        {
            st.erase(ele);
        }
    }
    cout<<st.size()<<endl;
    return 0;
}