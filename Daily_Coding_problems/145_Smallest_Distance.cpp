/*
Given an integer array, nums, return all pairs of numbers whose difference equals the minimum 
difference in the array.

Ex: Given the following nums…

nums = [4, 2, 3], return [[2, 3], [3, 4]] (the minimum difference between any two elements 
is one and 3 - 2 = 1 and 4 - 3 = 1).
Ex: Given the following nums…

nums = [6, 2, 5, 3, 1], return [[1, 2], [2, 3], [5, 6]].
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int cnt=0;
    map<int,vector<vector<int>>>mp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int diff=abs(nums[i]-nums[j]);
            vector<int>res={nums[i],nums[j]};
            mp[diff].push_back(res);
        }
    }
    auto it=mp.begin();
    for(auto ele:it->second)
    {
        cout<<ele[0]<<" "<<ele[1]<<endl;
    }
    return 0;

}