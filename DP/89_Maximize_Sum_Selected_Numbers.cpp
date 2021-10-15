/*
Given an array of N numbers, we need to maximize the sum of selected numbers.
At each step, you need to select a number Ai, delete one occurrence of it and 
delete all occurrences of Ai-1 and Ai+1 (if they exist) in the array. Repeat these
steps until the array gets empty. The problem is to maximize the sum of the selected numbers.
Note: We have to delete all the occurrences of Ai+1 and Ai-1 elements if they are
present in the array and not Ai+1 and Ai-1.
Examples: 
 

Input : a[] = {1, 2, 3} 
Output : 4
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int>mp;
    int n1;
    cin>>n1;
    for(int i=0;i<n1;i++)
    {
        int num;
        cin>>num;
        mp[num]++;
    }
    vector<int>res;
    for(auto it:mp)
    {
        res.push_back(it.first);
    }
    int n=res.size();
    vector<int>dp(n,0);
    dp[0]=res[0]*mp[res[0]];

    for(int i=1;i<n;i++)
    {
        if(res[i]==res[i-1]+1)
        {
            int temp=res[i]*mp[res[i]];
            if(i>=2)
            {
                temp+=dp[i-2];
            }
            dp[i]=max(temp,dp[i-1]);
        }
        else
        {
            dp[i]=dp[i-1]+res[i]*mp[res[i]];
        }
    }
    cout<<dp[n-1]<<endl;
}

// Time Complexity:O(n)
// Space Complexity:O(n)