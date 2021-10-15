#include <bits/stdc++.h>

using namespace std;

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n==1)
	    {
	        return arr[0];
	    }
	    if(n==2)
	    {
	        return max(arr[0],arr[1]);
	    }
	    int a=arr[0];
	    int b=max(arr[0],arr[1]);
	    int c;
	    for(int i=2;i<n;i++)
	    {
	        c=max(b,a+arr[i]);
	        a=b;
	        b=c;
	    }
	    return c;
	}
};

// time complexity: O(n)
// Space somplexity: O(1)


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends