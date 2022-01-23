#include<bits/stdc++.h>
using namespace std;


int CountSubsets(int arr[],int n,int i,int sum,int count)
{
    // base condition
    // if we reached to the destination i.e. end  of the array, then return count
    if(i==n)
    {
        if(sum==0)
        {
            count++;
        }
        return count;
    }


    // now we have two chioces for every element
    // either we include it our sum or we can exclude it 
    count=CountSubsets(arr,n,i+1,sum-arr[i],count);
    count=CountSubsets(arr,n,i+1,sum,count);
    return count;
}
// Time Complexity: Exponentional
// Space Complxity:O(1)




// Optimise 
// Memoization
#define maxN 20
#define maxSum 50
#define minSum 50
#define base 50
 
// To store the states of DP
int dp[maxN][maxSum + minSum];
bool v[maxN][maxSum + minSum];
 
// Function to return the required count
int findCnt(int* arr, int i, int required_sum, int n)
{
    // Base case
    if (i == n) {
        if (required_sum == 0)
            return 1;
        else
            return 0;
    }
 
    // If the state has been solved before
    // return the value of the state
    if (v[i][required_sum + base])
        return dp[i][required_sum + base];
 
    // Setting the state as solved
    v[i][required_sum + base] = 1;
 
    // Recurrence relation
    dp[i][required_sum + base]
        = findCnt(arr, i + 1, required_sum, n)
          + findCnt(arr, i + 1, required_sum - arr[i], n);
    return dp[i][required_sum + base];
}


int CountSumSubArray(int arr[],int sum,int n)
{
    int tab[n+1][sum+1];  // Initilization of array
    tab[0][0]=1;   //Initialization first value of matrix
    for(int i=1;i<=sum;i++)  // Initialise all elements as a 0 in first position of each column ( sum column)
    {
        tab[0][i]=0;
    }
    for(int i=0;i<=n;i++)    // Initialise all elements as a 1 in first element of each row (number of elements)
    {
        tab[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            // if sum less than j hai to add kernge hi ,,kya pta aage ja kr uska sathi mil jaye
            if(arr[i-1]<=j)
              tab[i][j]=tab[i-1][j-arr[i-1]]+tab[i-1][j]; 
          else
              tab[i][j]=tab[i-1][j];
        }
    }
    return tab[n][sum];
}
// Time Complexity:O(n*sum)
// Space Complexity:O(n*sum)


int main()
{
    int n=3;
    int arr[] = {0,1,0};
    int sum=1;
    //sort(arr,arr+n);
    cout<<"Number of subsets of given sum is : "<<(CountSumSubArray(arr,sum,n))<<endl;
    return 0;

}