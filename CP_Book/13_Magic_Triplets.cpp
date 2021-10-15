// In this problem we are going to find the triplets where i<j<k i.e. arr[i]<arr[j]<arr[k]


// same we can do it for 2 numbers also
#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
	int countTriplets(vector<int>nums){
	    int n=nums.size();
	    int count=0;
	    for(int i=1;i<n-1;i++)
	    {
	        int j=i-1;
	        int k=i+1;
	        int lct=0;
	        int rct=0;
	        while(j>=0)
	        {
	            if(nums[j]<nums[i])
	            {
	                lct++;
	            }
	            j--;
	        }
	        while(k<nums.size())
	        {
	            if(nums[i]<nums[k])
	            {
	                rct++;
	            }
	            k++;
	        }
	        count+=(lct*rct);
	        
	    }
	    return count;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}  