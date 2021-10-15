// Number of ways to participate N elements into k sets
/*
  Recursive Formula:  S(n,k)=k*(S(n-1,k)) + S(n1,k-1);
*/

#include<bits/stdc++.h>
using namespace std;


//Recursive
int CountP(int n,int k)
{
    // Base Case
    if(n==0 || k==0 || k>n)
    {
        return 0;
    }

    if(k==1 || k==n)
    {
        return 1;
    }

    // Formula
    // S(n+1, k) = k*S(n, k) + S(n, k-1) 
    return k*CountP(n-1, k) + CountP(n-1, k-1); 
}
/*
Time complexity: O(2^n). 
For every value of n, two recursive function is called. More specifically the Time 
complexity is exponential.


Space complexity: O(n)(Due to call stack).  
*/

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    cout<<CountP(n,k)<<endl;
}











// A Dynamic Programming based C++ program to count 
// number of partitions of a set with n elements 
// into k subsets 
#include<iostream> 
using namespace std; 

// Returns count of different partitions of n 
// elements in k subsets 
int countP(int n, int k) 
{ 
// Table to store results of subproblems 
int dp[n+1][k+1]; 

// Base cases 
for (int i = 0; i <= n; i++) 
	dp[i][0] = 0; 
for (int i = 0; i <= k; i++) 
	dp[0][k] = 0; 

// Fill rest of the entries in dp[][] 
// in bottom up manner 
for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= min(i,k); j++) 
	if (j == 1 || i == j) 
		dp[i][j] = 1; 
	else
		dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1]; 

return dp[n][k]; 
} 

// Driver program 
int main() 
{ 
cout << countP(8, 3); 
return 0; 
} 

/*
Time complexity:O(n*k). 
The 2D dp array of size n*k is filled, so the time Complexity is O(n*k).


Space complexity:O(n*k). 
An extra 2D DP array is required.
*/