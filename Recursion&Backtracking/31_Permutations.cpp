/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/


#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>&res,vector<vector<int>>&ans,vector<int>&ds,vector<int>&visited)
{
    if(ds.size()==res.size())
    {
        ans.push_back(ds);
        return;
    }

    for(int i=0;i<res.size();i++)
    {
        if(!visited[i])
        {
            ds.push_back(res[i]);
            visited[i]=1;
            solve(res,ans,ds,visited);  
            visited[i]=0;
            ds.pop_back();
        }
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
    vector<vector<int>>ans;
    vector<int>ds;
    vector<int>visited(n,0);
    solve(res,ans,ds,visited);
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
// Space Complexity:O(n)