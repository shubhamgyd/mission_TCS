/*
Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

*/

#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>&res,int i,vector<vector<int>>&ans,vector<int>&ds)
{
    ans.push_back(ds);
    for(int ind=i;ind<res.size();ind++)
    {
        // if duplicates occurs then we will ignore it
        if(ind!=i && res[ind]==res[ind-1]) continue;

        // we have two choices either select it or ignore it ( it it is a distinct element)
        ds.push_back(res[ind]);
        solve(res,ind+1,ans,ds);
        ds.pop_back();
    }

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
    sort(res.begin(),res.end());
    vector<vector<int>>ans;
    vector<int>ds;
    solve(res,0,ans,ds);
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
// Time Complexity:O(2^k*n)
// Space Complexity:O(n)