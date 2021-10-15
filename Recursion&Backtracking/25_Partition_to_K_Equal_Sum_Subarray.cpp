#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool backtrack(vector<int>& nums,int curr_sum,int k,int n,int target,int i,vector<bool>&visited)
    {
        // Here we found all the k subsets
        if(k==0)
        {
            return true;
        }
        

        // if we get the cum equal to the target value
        if(curr_sum==target)
        {
            // Start backtrack for next subset from begining of the array, by reducing k by 1
            return backtrack(nums,0,k-1,n,target,0,visited);
        }
        

        // Iterate to all elements of the array
        for(int j=i;j<n;j++)
        {
            // If the current element is not visited and the previous sum +current sum is less thant 
            // equal to the target then mark visited this element and check for the next value
            if(!visited[j] && curr_sum+nums[j]<=target)
            {
                // Mark the current value as the visited
                visited[j]=true;
                
                // Check for next value in the array should satisfy the condition if yes, then
                /// return yes
                if(backtrack(nums,curr_sum+nums[j],k,n,target,j+1,visited))
                {
                    return true;
                }
                // else unmakr it and check for next array element
                visited[j]=false;
            }
        }

        // If we didn't get desired subarry with target value then simply return false
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int target,remain;
        int temp=accumulate(nums.begin(),nums.end(),0);
        
        // Target valuse of each subarray
        target=temp/k;


        // If sum if odd then we can't divide it into k equal parts
        if(temp%k>0)
        {
            return false;
        }

        vector<bool>visited(n,false);

        // Start backtrack from 0th index,with 0 sum
        return backtrack(nums,0,k,n,target,0,visited);
    }
};