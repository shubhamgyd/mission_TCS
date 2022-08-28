/*
This problem was asked by Etsy.

Given an array of numbers N and an integer k, your task is to split N into k partitions such that the 
maximum sum of any partition is minimized. Return this sum.

For example, given N = [5, 1, 2, 7, 3, 4] and k = 3, you should return 8, since the optimal partition 
is [5, 1, 2], [7], [3, 4].
*/


#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l=0,r=0;
        int n=nums.size();
        for(int i=0;i<n;++i) 
        {
            l=max(l,nums[i]);
            r+=nums[i];
        }
            
        int ans=0,mid=0;
        while(l<=r){
            //mid=(l+r)/2;
            mid=l+(r-l)/2;
            int cnt=0,tsum=0;//temp sum
            for(int i=0;i<n;++i){
                if(tsum+nums[i]<=mid) tsum+=nums[i];
                else cnt++,tsum=nums[i];
            }
            cnt++; 
            
            if(cnt<=m) r=mid-1, ans=mid;
            else l=mid+1;
        }  
        return ans;

    }
};

/*
Time Complexity : O(N*log(Sum)) 
Where N is the number of elements of the array and Sum is the sum of all the elements of the array.
*/

void solve(int n,int k,int ind,int sum,int mxSum,vector<int>&nums,int& ans)
{
    // base case
    if(k==1)
    {
        mxSum=max(mxSum,sum);
        sum=0;
        for(int i=ind;i<n;i++)
        {
            sum+=nums[i];
        }
        mxSum=max(mxSum,sum);
        ans=min(ans,mxSum);
    }
    else
    {
        sum=0;
        for(int i=ind;i<n;i++)
        {
            sum+=nums[i];
            mxSum=max(mxSum,sum);
            solve(n,k-1,i+1,sum,mxSum,nums,ans);
        }
    }
}
/*
Time Complexity: O((N−1)c(K−1) (NOTE: ‘c’ here depicts combinations i.e. ((n-1)!/((n-k)!*(k-1)!)
Where N is the number of elements of the array and K is the number of divisions.
*/

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int k;
    cin>>k;
    int ans=INT_MAX;
    solve(n,k,0,0,0,nums,ans);
    cout<<ans<<endl;
    return 0;
}