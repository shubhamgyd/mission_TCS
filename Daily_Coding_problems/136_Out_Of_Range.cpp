/*
You are given two bounds, lower and upper and a sorted integer array, nums. Return a list of strings
 that represents the missing ranges between lower and upper that are not covered in nums.

Ex: Given the following nums, lower, and upper…

nums = [2, 5, 7], lower = 0, upper = 10, return ["0->1","3->4","6","8->10"] 
(0 - 1, 3 - 4, 6, and 8 - 10 are not covered in nums).
Ex: Given the following nums, lower, and upper…

nums = [], lower = 15, upper = 20, return ["15->20"].
*/

#include<bits/stdc++.h>
using namespace std;

int totalTurns(char* input1,int input2,int input3)
{
    int len=sizeof(input1)/sizeof(input1[0]);
    int n=input3;
    int m=input2;
    // int x=n+m;
    // if(len%x==0)
    // {
    //     int res=(x<<1);
    //     int ans=len/res;
    //     return ans;
    // }
    // elif(ls%x==n):
    //     print((ls//x<<1)+1)
    
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
    int lower,upper;
    cin>>lower>>upper;
    vector<string>ans;
    unordered_map<int,int>mp;
    for(auto it:nums) mp[it]++;
    string str="";
    int cnt=0;
    while(lower<=upper)
    {
        if(mp.find(lower)!=mp.end())
        {
            if(cnt==1)
            {
                ans.push_back(str);
                str="";
            }
            else
            {
                str+="->";
                str+=to_string(lower-1);
                ans.push_back(str);
                str="";
            }
            cnt=0;
        }
        else
        {
            if(cnt==0)
            {
                str=to_string(lower);
            }
            cnt++;
        }
        lower++;
    }
    if(str.length()!=0)
    {
        if(cnt==1)
        {
            ans.push_back(str);
        }
        else
        {
            str+="->";
            str+=to_string(lower-1);
            ans.push_back(str);
        }
    }
    for(auto it:ans)
    {
        cout<<it<<" , ";
    }
}