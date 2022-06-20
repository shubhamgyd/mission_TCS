/*
Problem Statement: Given an array of N integers. Find the elements that appears more than 
N/3 times in the array. If no such element exists, return an empty vector.

Example 1:

Input: N = 5, array[] = {1,2,2,3,2}

Ouput: 2

Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.
Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.
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

    // Brute force
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(res[i]==res[j]) cnt++;
        }
        if(cnt>n/3)
        {
            cout<<res[i]<<endl;
            break;
        }
    }
    // Time :O(n*n)
    // Space: O(1)



    // Using Counting Sort - nlogn - Hashmap
    // Using Freq Sort - n 
    map<int,int>mp;
    for(auto it:res)
    {
        mp[it]++;
    }
    for(auto it:mp)
    {
        if(it.second>n/3)
        {
            cout<<it.first<<endl;
            break;
        }
    }
    // Time :O(nlogn)
    // Space :O(n)

    // using sorting
    vector<int>temp=res;
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++)
    {
        
        int last=i+n/3+1;
        // cout<<"i: "<<i<<" last: "<<last<<endl;
        if(res[i]==res[last])
        {
            cout<<res[i]<<endl;
            break;
        }
    }
    // T:O(logn)
    // S:O(1)
    

    // Extended Boyer Moore’s Voting Algorithm
    vector<int>nums=res;
    int sz = nums.size();
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
        for (i = 0; i < sz; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }    
            else if (count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = count2 = 0;
        for (i = 0; i < sz; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
        }
        if (count1 > sz/3)
            ans.push_back(num1);
        if (count2 > sz/3)
            ans.push_back(num2);
        cout<<ans[0]<<endl;
        // T:O(n)
        // S:O(1)
}