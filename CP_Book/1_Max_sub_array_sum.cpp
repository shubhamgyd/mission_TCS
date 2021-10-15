#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);      // for stabdard input and output
    cin.tie(0);
    int arr[]={-4 -3 -2 -1};
    int n=sizeof(arr)/sizeof(arr[0]);     //size of array
    int base=0,sum=0;
    for(int i=0;i<n;i++)          // Running in O(n) time complexity 
    {
        sum=max(arr[i],sum+arr[i]);    // comparing the maximum sum+array[i] and given element of array
        base=max(base,sum);            // Comparing the maximum suma nd base 
    }
    cout<<" Maximum sum of maximum subarrya:" <<base<<"\n";
}