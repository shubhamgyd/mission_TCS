/*
This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), 
find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&a,vector<int>&b)
{
    return a[1]<b[1];
}

int main()
{
    int n;
    cin>>n;
    // cout<<n<<endl;
    vector<vector<int>>res;
    for(int i=0;i<n;i++)
    {
        // cout<<"k"<<endl;
        int a,b;
        cin>>a>>b;
        // cout<<a<<" "<<b<<endl;
        vector<int>ans;
        ans.push_back(a);
        ans.push_back(b);
        res.push_back(ans);
    }
    sort(res.begin(),res.end(),cmp);
    for(auto it:res)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }

    int i=0;
    int ct=0;
    while(i<n)
    {
        int end=res[i][1];
        int j=i+1;
        while(j<n && ( res[j][0]<=end || res[j][1]<=end))
        {
            int num1=res[j][1];
            if(num1<end)
            {
                end=num1;
            }
            j++;
        }
        ct++;
        i=j;
    }
    cout<<ct<<endl;
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(1)