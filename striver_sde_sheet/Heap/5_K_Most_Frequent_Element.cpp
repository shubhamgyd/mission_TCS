/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int>mp;
    for(auto it:arr)
    {
        mp[it]++;
    }
    priority_queue<pair<int,int>>pq;
    for(auto it:mp)
    {
        pq.push({it.second,it.first});
    }
    vector<int>ans;
    while(k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{

}