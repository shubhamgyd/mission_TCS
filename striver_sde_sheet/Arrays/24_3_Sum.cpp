/*
Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give sum zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

Examples:

Example 1: 

Input: nums = [-1,0,1,2,-1,-4]

Output: [[-1,-1,2],[-1,0,1]]

Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of summing up to zero with i!=j!=k

Example 2:

Input: nums=[-1,0,1,0]
Output: Output: [[-1,0,1],[-1,1,0]]
Explanation: Out of all possible unique triplets possible, [-1,0,1] and [-1,1,0] satisfy the condition of summing up to zero with i!=j!=k
*/

#include<bits/stdc++.h>
using namespace std;


// Another Solution of Ignoring Deplicates
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>s;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1;
            int k=n-1;
            int t=-nums[i];
            while(j<k)
            {
                vector<int>v;
                int sum=nums[j]+nums[k];
                if(sum<t)
                {
                    j++;
                }
                else  if(sum>t)
                {
                    k--;
                }
                else
                {
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    s.push_back(v);
                    while (j<k && nums[j] == v[1]) j++;
                    while (j<k && nums[k] == v[2]) k--;
                }
            }
            while(i +1 <n && nums[i+1]==nums[i]) i++;
        }
        return s;
    }
};



int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }

    // Brute force
    set<tuple<int,int,int>>st;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(res[i]+res[j]+res[k]==0)
                {
                    tuple<int,int,int>t(res[i],res[j],res[k]);
                    st.insert(t);
                }
            }
        }
    }
    cout<<"Triplets: "<<endl;
    for(auto it:st)
    {
        int u,v,w;
        tie(u,v,w)=it;
        cout<<u<<","<<v<<","<<w<<endl;
    }
    // T:O(n^3)
    // S:O(3*k)

    // Using Three Pointer
    set<tuple<int,int,int>>st1;
    sort(res.begin(),res.end());
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        int k=n-1;
        int target=0-res[i];
        while(j<k)
        {
            if(res[j]+res[k]==target)
            {
                tuple<int,int,int>t={res[i],res[j],res[k]};
                st1.insert(t);
                j++;
                k--;
            }
            else if(res[j]+res[k]<target) j++;
            else k--;
        }
    }
    cout<<"Truplets: "<<endl;
    for(auto it:st1)
    {
        int u,v,w;
        tie(u,v,w)=it;
        cout<<u<<" "<<v<<" "<<w<<endl;
    }
    // T:O(n*n)
    // S:O(3*n);
    return 0;
}