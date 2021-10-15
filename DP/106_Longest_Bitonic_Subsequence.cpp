#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();

        // Longest increasing subsequence
	    int lis[n];
	    for(int i=0;i<n;i++)
	    {
	        lis[i]=1;
	        
	    }
	    
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(nums[i]>nums[j] && lis[i]<lis[j]+1)
	            {
	                lis[i]=lis[j]+1;
	            }
	        }
	    }
	    

        // Longest decreasing Subsequence
	    int lds[n];
	    for(int i=0;i<n;i++)
	    {
	        lds[i]=1;
	    }
	    
	    for(int i=n-2;i>=0;i--)
	    {
	        for(int j=n-1;j>i;j--)
	        {
	            if(nums[i]>nums[j] && lds[i]<lds[j]+1)
	            {
	                lds[i]=lds[j]+1;
	            }
	        }
	    }
	    
	    int val=lis[0]+lds[0]-1;
	    for(int i=1;i<n;i++)
	    {
	        val=max(val,lis[i]+lds[i]-1);
	    }
	    return val;
	}
};
// Time Complexity :O(n*n)
// Space Complexity O(n)




// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends