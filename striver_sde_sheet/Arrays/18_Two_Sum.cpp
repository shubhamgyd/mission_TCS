/*
Problem Statement: Given an array of integers nums[] and an integer target, return indices of the two numbers such that their sum is equal to the target.

Note: Assume that there is exactly one solution, and you are not allowed to use the same element twice. Example: If target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

Example 1:

Input: nums = [2,7,11,15], target = 9

Output: [0,1]

Explanation: Because nums[0] + nums[1] == 9, which is the required target, we return indexes [0,1]. (0-based indexing)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }

    int target;
    cin>>target;
    // brute force
    bool ok=false;
    for(int i=0;i<n;i++)
    {
        int num=target-res[i];
        for(int j=i+1;j<n;j++)
        {
            if(res[j]==num)
            {
                cout<<"Found"<<endl;
                ok=true;
                break;
            }
        }
        if(ok)
        {
            break;
        }
    }
    if(!ok) cout<<"Not Found"<<endl;
    // T:O(n*n)
    // S:O(1)


    // using hashmap
    map<int,int>mp;
    bool ok1=false;
    
    for(auto it:res)
    {
        if(mp.find(target-it)!=mp.end())
        {
            cout<<"Found"<<endl;
            ok1=true;
            break;
        }
        mp[it]++;
    }
    if(!ok1)
    {
        cout<<"Not Found"<<endl;
    }
    // T:O(n)
    // S:O(n)


    // Using Two pointer approach
    sort(res.begin(),res.end());
    int i=0;
    int j=n-1;
    bool ok2=false;
    while(i<j)
    {
        if(res[i]+res[j]>target)
        {
            j--;
        }
        else if(res[i]+res[j]<target)
        {
            i--;
        }
        else
        {
            cout<<"Found"<<endl;
            ok2=true;
            break;
        }
    }
    if(!ok2)
    {
        cout<<"Not Found"<<endl;
    }
    // T:O(nlogn)
    // S:O(1)

}