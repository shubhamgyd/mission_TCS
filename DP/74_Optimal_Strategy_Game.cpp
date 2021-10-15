#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



//Function to find the maximum possible amount of money we can win.
int dp[1001][1001];                // dp table to store the result
int solve(int i,int j,int arr[])
{
    if(i>j) return 0;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int x=arr[i]+min(solve(i+2,j,arr),solve(i+1,j-1,arr));
    int y=arr[j]+min(solve(i,j-2,arr),solve(i+1,j-1,arr));
	//cout<<"X: "<<x<<" Y: "<<y<<endl;
    return dp[i][j]=max(x,y);
}


// int dp1[1001][1001];                // dp table to store the result
// int solve1(int i,int j,int arr[])
// {
//     if(i>j) return 0;
//     if(dp1[i][j]!=-1)
//     {
//         return dp1[i][j];
//     }
//     int x=arr[i]+min(solve1(i+2,j,arr),solve1(i+1,j-1,arr));
//     int y=arr[j]+min(solve1(i,j-2,arr),solve1(i+1,j-1,arr));
// 	cout<<"X: "<<x<<" Y: "<<y<<endl;
//     return dp1[i][j]=max(x,y);
// }






/*
The intuition behind this is , 

1. if player choose the ith position element from starting  , then he has two choices
for next time he choose the elemnt between range(i+2,j) or (i+1,j-1) 
and take the minimum of this two

2. if player choose jth position element from the ending , then he has two choices to select the element
for next time . Either he chooses element between range(i,j-2) or (i+1,j-1) and thake the minimum of this
two

lastly add this result to the dp table with corresponding  value of i,j

*/

long long maximumAmount(int arr[], int n) 
{
    // Your code here
    memset(dp,-1,sizeof(dp));
    return solve(0,n-1,arr);
}

// long long maximumAmount1(int arr[],int n)
// {
// 	memset(dp1,-1,sizeof(dp1));
// 	return solve1(1,n-1,arr);
// }

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
		//cout<<maximumAmount1(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends



















// DP Solution

// C++ program to find out
// maximum value from a given
// sequence of coins
#include <bits/stdc++.h>
using namespace std;

// Returns optimal value possible
// that a player can collect from
// an array of coins of size n.
// Note than n must be even
int optimalStrategyOfGame(
	int* arr, int n)
{
	// Create a table to store
	// solutions of subproblems
	int table[n][n];

	// Fill table using above
	// recursive formula. Note
	// that the table is filled
	// in diagonal fashion (similar
	// to http:// goo.gl/PQqoS),
	// from diagonal elements to
	// table[0][n-1] which is the result.
	for (int gap = 0; gap < n; ++gap) {
		for (int i = 0, j = gap; j < n; ++i, ++j) {
			// Here x is value of F(i+2, j),
			// y is F(i+1, j-1) and
			// z is F(i, j-2) in above recursive
			// formula
			int x = ((i + 2) <= j)
						? table[i + 2][j]
						: 0;
			int y = ((i + 1) <= (j - 1))
						? table[i + 1][j - 1]
						: 0;
			int z = (i <= (j - 2))
						? table[i][j - 2]
						: 0;

			table[i][j] = max(
				arr[i] + min(x, y),
				arr[j] + min(y, z));
		}
	}

	return table[0][n - 1];
}

// Driver program to test above function
int main()
{
	int arr1[] = { 8, 15, 3, 7 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	printf("%d\n",
		optimalStrategyOfGame(arr1, n));

	int arr2[] = { 2, 2, 2, 2 };
	n = sizeof(arr2) / sizeof(arr2[0]);
	printf("%d\n",
		optimalStrategyOfGame(arr2, n));

	int arr3[] = { 20, 30, 2, 2, 2, 10 };
	n = sizeof(arr3) / sizeof(arr3[0]);
	printf("%d\n",
		optimalStrategyOfGame(arr3, n));

	return 0;
}
