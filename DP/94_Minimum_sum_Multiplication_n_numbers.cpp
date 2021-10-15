/*
Given n integers. The task is to minimize the sum of multiplication of all the 
numbers by taking two adjacent numbers at a time and putting back their sum % 100 till
a number is left. 
*/

// Note: This problem is a variation of matrix chain multiplication

#include<bits/stdc++.h>
using namespace std;
#define int long long 


int MinSum(int arr[],int n)
{
    vector<int>res(arr,arr+n);
    vector<int>ans(arr,arr+n);
    int val=0;
    while(res.size()!=1)
    {
        // cout<<"size: "<<res.size()<<endl;
        int mul=(res[0]*res[1]);
        val+=mul;
        int temp=(res[0]+res[1])%100;
        res.erase(res.begin(),res.begin()+2);
        if(temp!=0)  res.push_back(temp);
    }

    int val1=0;
    reverse(ans.begin(),res.end());
    while(ans.size()!=1)
    {
        // cout<<"size: "<<ans.size();
        int mul=(ans[0]*ans[1]);
        val1+=mul;
        int temp=(ans[0]+ans[1])%100;
        ans.erase(ans.begin(),ans.begin()+2);
        if(temp!=0) ans.insert(ans.begin(),temp);
    }
    // cout<<"val: "<<val<<endl;
    // cout<<"val1: "<<val1<<endl;
    return min(val,val1);
}


// Recursive approach

int MCM(int arr[],int i,int j)
{
    // base condition
    if(i>=j)
    {
        return 0;
    }
    int mn=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=MCM(arr,i,k)+MCM(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
       if(temp<mn)
       {
           mn=temp;
       }
    }
    return mn;
}


int32_t main()
{
    int arr[]={40,60,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Min  cost is: ";
    // cout<<MinSum(arr,n)<<endl;
    cout<<MCM(arr,1,n-1)<<endl;
    return 0;
}