/*
Problem Statement: 
    Given an array of intervals, merge all the overlapping intervals and return an array of 
    non-overlapping intervals.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector < pair < int, int >> arr;
    arr = {{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
    int n=arr.size();
    sort(arr.begin(),arr.end(),[](pair<int,int>&a,pair<int,int>&b){return a.first<b.first;});
    vector<vector<int>>res;
    res.push_back({arr[0].first,arr[0].second});
    for(int i=1;i<n;++i)
    {
        auto p=res.back();
        if(arr[i].first>p[1])
        {
            res.push_back({arr[i].first,arr[i].second});
        }
        else
        {
            res.back()[1]=max(p[1],arr[i].second);
        }
    }
    for(auto it:res)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    
}
// Time Complexity:O(nlogn)
// Space Complexity:O(n)