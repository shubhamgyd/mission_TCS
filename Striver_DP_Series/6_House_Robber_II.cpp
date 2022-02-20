/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at this place are
 arranged in a circle. That means the first house is the neighbor of the last one. 
 Meanwhile, adjacent houses have a security system connected, and it will automatically 
 contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), 
because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

int SpaceOptimize(vector<int>&res,int n)
{
    int prev=res[0];
    int nextPrev=0;
    for(int i=1;i<n;i++)
    {
        int take=res[i];
        if(i>1)
        {
            take+=nextPrev;
        }
        int nonTake=prev;
        int curr=max(take,nonTake);
        nextPrev=prev;
        prev=curr;
    }
    return prev;
}
// Time Complexity:O(n)
// Space Complexity:O(1)


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    vector<int>temp1,temp2;
    for(int i=0;i<n;i++)
    {
        if(i!=0) temp1.push_back(res[i]);
        if(i!=n-1) temp2.push_back(res[i]);
    }
    int temp=max(SpaceOptimize(temp1,temp1.size()),SpaceOptimize(temp2,temp2.size()));
    cout<<temp<<endl;
    return 0;
}