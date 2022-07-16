#include <bits/stdc++.h>
using namespace std;
 
// Function to reduce an integer N
// to Zero in minimum operations by
// removing digits from N
int reduceZero(int N)
{
	// Initialise dp[] to steps
	vector<int> dp(N + 1, 1e9);
 
	dp[0] = 0;
 
	// Iterate for all elements
	for (int i = 0; i <= N; i++) {
 
		// For each digit in number i
		for (char c : to_string(i)) {
 
			// Either select the number
			// or do not select it
			dp[i] = min(dp[i],
						dp[i - (c - '0')]
							+ 1);
		}
	}
 
	// dp[N] will give minimum
	// step for N
	return dp[N];
}
 
// Driver Code
int main()
{
	// Given Number
	int n;
	cin>>n;
	cout << reduceZero(n);
	return 0;
}