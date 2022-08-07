/*
Suppose at the first level of a tree a root node is always present. You are given an array count where count[i] denotes the number of nodes present at the ith level. We need to output the maximum diameter(number of edges in the longest path) possible for this tree.

input :arr[]={2}
output :2
*/

#include<bits/stdc++.h>
using namespace std;

pair<int,int> solve(int i,vector<int>&nums)
{
    // base case
    if(i>=nums.size())
    {
        return {0,0};
    }
    int max_dia_len=0;
    while( i< nums.size() and nums[i]>1)
    {
        max_dia_len+=2;
        i++;
    }
    int path_len=max_dia_len/2;
    if(i<nums.size())
    {
        // Whenever encountered a level nodes with value 1, recurse and find diameter of current root node.
        auto res=solve(i+1,nums);
        int ith_node_dia=res.first;
        int ith_path_len=res.second;
        ith_path_len++;
        return {max(ith_node_dia,ith_path_len+max_dia_len),ith_path_len+path_len};
    }
    return {max(max_dia_len,path_len),path_len};
}

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    auto ans=solve(0,nums);
    cout<<ans.first<<endl;
    // cout<<ans.second<<endl;
    return 0;
}