// C++ implementation to count number of 
// increasing subsequences of size k 
#include <bits/stdc++.h> 

using namespace std; 

// function to count number of increasing 
// subsequences of size k 
int numOfIncSubseqOfSizeK(int arr[], int n, int k) 
{ 
	int dp[n][k+1], sum = 0; 
	memset(dp, 0, sizeof(dp)); 

	// count of increasing subsequences of size 1 
	// ending at each arr[i] 
	for (int i = 0; i <n; i++) 
		dp[i][1] = 1; 

    for(int i=1;i<n;i++)
    {
      for(int j=0;j<i;j++)
      {
        if(arr[i]>arr[j])
        {
         for(int l=1;l<=k;l++)
           if(dp[j][l]!=0)
           dp[i][l+1]+=dp[j][l];
        }
      }
    }
  
    
	// sum up the count of increasing subsequences of 
	// size 'k' ending at each element arr[i] 
	for (int i = 0; i < n; i++) 
		sum += dp[i][k]; 

	// required number of increasing 
	// subsequences of size k 
	return sum; 
} 

// Driver program to test above 
int main() 
{ 
	int arr[] = { 12, 8, 11, 13, 10, 15, 14, 16, 20 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 4; 

	cout << "Number of Increasing Subsequences of size "
		<< k << " = " << numOfIncSubseqOfSizeK(arr, n, k); 

	return 0; 
} 
// Time Complexity :O(n*n*k)
// Space Complexity :O(n*k)