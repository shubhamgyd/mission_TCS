#include<bits/stdc++.h>
using namespace std;

// Intitution behind this is CealSearch from Binary Search.
class Solution
{
    int ceilSearch(int dp[],int low,int high,int target)
    {
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(dp[mid]>=target)
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return high;
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int l=1;
        int dp[n];
        dp[0]=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]>dp[l-1])
            {
                dp[l]=a[i];
                l++;
            }
            else
            {
                int c=ceilSearch(dp,0,l-1,a[i]);
                dp[c]=a[i];
            }
        }
        return l;
    }
};


// Another Approach

/*
set<int> s;
		for (auto a : nums) {
			if (s.find(a) != s.end()) continue;
			s.insert(a);
			auto it = s.upper_bound(a);
			if (it != s.end()) s.erase(it);
		}
		return s.size();






int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}




*/





// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}