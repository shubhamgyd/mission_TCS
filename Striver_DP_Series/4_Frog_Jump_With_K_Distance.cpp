/*
Problem Statement:
This is a follow-up question to “Frog Jump” discussed in the previous article. 
In the previous question, the frog was allowed to jump either one or two steps at a time. 
In this question, the frog is allowed to jump up to ‘K’ steps at a time. 
If K=4, the frog can jump 1,2,3, or 4 steps at every index.
*/



/*
Memoization approach

Steps to convert Recursive code to memoization solution:

Create a dp[n] array initialized to -1.
Whenever we want to find the answer of a particular value (say n), we first check
 whether the answer is already calculated using the dp array(i.e dp[n] != -1 ). 
 If yes, simply return the value from the dp array.
If not, then we are finding the answer for the given value for the first time, 
we will use the recursive relation as usual but before returning from the function, 
we will set dp[n] to the solution we get.
*/


#include <bits/stdc++.h>
using namespace std;

int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int mmSteps = INT_MAX;
        
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
      int jump = solveUtil(ind-j, height, dp, k)+ abs(height[ind]- height[ind-j]);
            mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind]= mmSteps;
    
}

int solve(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return solveUtil(n-1, height, dp, k);
}

int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  int k=2;
  vector<int> dp(n,-1);
  cout<<solve(n,height,k);
}

/*
Time Complexity: O(N *K)
Reason: The overlapping subproblems will return the answer in constant time. 
Therefore the total number of new subproblems we solve is ‘n’. At every new subproblem,
 we are running another loop for K times. Hence total time complexity is O(N * K).

Space Complexity: O(N)
Reason: We are using a recursion stack space(O(N)) and an array (again O(N)).
Therefore total space complexity will be O(N) + O(N) ≈ O(N)
*/