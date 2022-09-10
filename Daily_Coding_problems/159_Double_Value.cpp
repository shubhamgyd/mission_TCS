/*
Given an integer array, nums, return true if for any value within nums its double also exists 
within the array.

Ex: Given the following nums…

nums = [4, 3, 9, 8], return true (4 and 8 both appear in nums).
Ex: Given the following nums…

nums = [9, 2, 3, 5], return false.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    // Brute Force
    bool ok=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(nums[j]/2==nums[i])
            {
                ok=true;
                cout<<nums[i]<<" "<<nums[j]<<endl;
                break;
            }
        }
        if(ok)
        {
            break;
        }
    }
    if(!ok)
    {
        cout<<-1<<endl;
    }

    unordered_map<int,int>mp;
    for(auto it:nums)
    {
        mp[it]++;
    }
    bool ok1=false;
    for(auto it:nums)
    {
        if(mp.find(it/2)!=mp.end())
        {
            cout<<it<<" "<<it/2<<endl;
            ok1=true;
            break;
        }
    }
    if(!ok1)
    {
        cout<<"-1"<<endl;
    }
    return 0;
}