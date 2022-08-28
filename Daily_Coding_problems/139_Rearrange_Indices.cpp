/*
Given a string s and an integer array, indices, you must rearrange s according to the given 
indices. Once you have rearranged s successfully, the ith character in s should now be 
located at the indices[i] index.
Note: s and indices will always be the same length.

Ex: Given the following s and indices…

s = "abc", indices = [2, 1, 0], return "cba" ('a' moves to the 2nd index, b stays at the 
first index, and c moves to the zeroth 
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    
    string str;
    cin>>str;
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    string ans="";
    ans.resize(n);
    int ind=0;
    for(auto it:nums)
    {
        char ch=str[it];
        ans[ind++]=ch;
    }
    cout<<ans<<endl;
    return 0;
}