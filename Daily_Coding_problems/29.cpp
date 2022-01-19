/*
his question is asked by Google. Given two integer arrays, return their intersection.
Note: the intersection is the set of elements that are common to both arrays.

Ex: Given the following arrays...

nums1 = [2, 4, 4, 2], nums2 = [2, 4], return [2, 4]
nums1 = [1, 2, 3, 3], nums2 = [3, 3], return [3]
nums1 = [2, 4, 6, 8], nums2 = [1, 3, 5, 7], return []
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int>&nums1,vector<int>&nums2)
{
    unordered_map<int,int>mp;
    for(auto it:nums1)
    {
        mp[it]++;
    }
    set<int>st;
    for(auto it:nums2)
    {
        if(mp.find(it)!=mp.end())
        {
            st.insert(it);
            mp[it]--;
            if(mp[it]==0)
            {
                mp.erase(it);
            }
        }
    }
    vector<int>res(st.begin(),st.end());
    return res;
}


int main()
{
    
}