#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	int findMaxSubarraySum(long long arr[], int n, long long k)
	{
	   long long int i=0,sum=0,res=0;
	   for(int j=0;j<n;j++)
	   {
	       sum+=arr[j];
	       while(i<=j && sum>k)
	       {
	           sum-=arr[i++];
	       }
	       res=max(res,sum);
	   }
	   return res;
	}  

		 

};
	  
// Another approach using the set in O(nlon(n)) time

class STL
{
public:
	int findSum(long long arr[],int n,long long k)
	{

		// Hash to lookup the csum-k;
		set<int>cum_set;
		cum_set.insert(0);

		int max=INT_MIN;
		int cSum=0;
		for(int i=0;i<N;i++)
		{
			cSum+=arr[i];
			// check if upper_bound
			// of (cSum-K) exists
			// then update max sum
			auto it=cum_set.lower_bound(cSum-*it);
			if(it!=cum_set.end())
			{
				mx=max(mx,cSum-*it);
			}
			cum_set.insert(cSum);
		}
		return mx;
	}
};



// { Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends