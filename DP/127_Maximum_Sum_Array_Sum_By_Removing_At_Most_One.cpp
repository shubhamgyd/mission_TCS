#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(int A[], int n)
    {
        //Your code here
        int fw[n];
        int bk[n];
        int sum=A[0];
        int base=A[0];
        fw[0]=A[0];
        
        for(int i=1;i<n;i++)
        {
            sum=max(A[i],sum+A[i]);
            base=max(base,sum);
            fw[i]=sum;
        }
        
        
        sum=A[n-1];
        base=A[n-1];
        
        bk[n-1]=A[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            sum=max(A[i],sum+A[i]);
            base=max(base,sum);
            bk[i]=sum;
        }
        
        int mx=base;
        
        for(int i=1;i<n-1;i++)
        {
            mx=max({mx,0,fw[i-1]+bk[i+1]});
            if(mx==0)
            {
                return *max_element(A,A+n);
            }
        }
        return mx;
    }
};