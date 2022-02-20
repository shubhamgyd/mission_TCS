/*
Given an array nums of distinct integers, return all the possible permutations.
 You can return the answer in any order
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int i,vector<int>&res,vector<vector<int>>&ans)
{
    if(i>=res.size())
    {
        ans.push_back(res);
        return;
    }
    for(int ind=i;ind<res.size();ind++)
    {
        swap(res[i],res[ind]);
        solve(i+1,res,ans);
        swap(res[i],res[ind]);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(auto &it:res)
    {
        cin>>it;
    }    
    vector<vector<int>>ans;
    // vector<int>temp;
    solve(0,res,ans);
    for(auto it:ans)
    {
        for(auto ele:it)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// Time Complexity:O(n!*n)
// Space Complexity:O(1) ignore stack space recursion