
// Min number of coins required to make given sum


// This problem is similar to number of subsequences having product less than k 
// just we have to make some changes

// #include<bits/stdc++.h>
// using namespace std;


// int CountCoin(int coin[] ,int sum,int n)
// {
//     int dp[n+1][sum+1];
//     // for(int i=0;i<=sum;i++)
//     // {
//     //     dp[0][i]=0;
//     // }
//     // for(int i=0;i<=n;i++)
//     // {
//     //     dp[i][0]=1;
//     // }

//     for(int i=0;i<=n;i++)
//     {
//         dp[i][0]=0;
//     }
//     for(int i=1;i<=sum;i++)
//     {
//         dp[0][i]=INT_MAX-1;
//     }

//     for(int j=1;j<=sum;j++)
//     {
        
//         if(j%coin[0]==0)
//             dp[1][j]=j/coin[0];
//         else
//             dp[1][j]=INT_MAX-1;
//     }

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=sum;j++)
//         {
//             if(coin[i-1]<=j)
//             {
//                 //dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
//                 dp[i][j]=min((dp[i][j-coin[i-1]]+1),dp[i-1][j]);
//             }
//             else
//             {
//                 dp[i][j]=dp[i-1][j];
//             }
//         }

//     }
//     if(dp[n][sum]==INT_MAX-1) return -1;
//     return dp[n][sum];
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int coin[] = {1,2,3};
//     int sum= 4;
//     int n=sizeof(coin)/sizeof(coin[0]);
//     cout<<"Maximum ways to change coin :"<<CountCoin(coin,sum,n)<<"\n";
//     return 0; 
// }








// Resurcisve approach

#include<bits/stdc++.h>
using namespace std;


int solve(int arr[],int sum,int n)
{
    // is sum==0 , then no need to add any coin
    if(sum==0)
    {
        return 1;
    }

    // is sum is not possible
    if(sum<0)
    {
        return 0;
    }


    // if no coins left and still sum is greater than 0
    if(n<=0 && sum>=1)
    {
        return 0;
    }

    // We have two choices
    //Either 1. Include the current coin 
    //       2. Exlude the current coint
    return solve(arr,sum-arr[n-1],n-1)+solve(arr,sum,n-1);
}

int main()
{
    int arr[5]={1,2,3};
    int sum=4;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<solve(arr,sum,n)<<endl;
    return 0;
}
/*
Time Complexity: O(2^k)
Space Complexity: O(1)
*/


// memoization
#include<bits/stdc++.h>
using namespace std;


int dp[101][101];
int solve(int arr[],int sum,int n)
{
    // is sum==0 , then no need to add any coin
    if(sum==0)
    {
        return dp[n][sum]=1;
    }

    // is sum is not possible
    if(n==0)
    {
        return 0;
    }


    // if we have already find the ways for this particular coin
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    // We have two choices
    //Either 1. Include the current coin 
    //       2. Exlude the current coint
    if(arr[n-1]<=sum)
    {
        return dp[n][sum]=solve(arr,sum-arr[n-1],n)+solve(arr,sum,n-1);
    }
    return dp[n][sum]=solve(arr,sum,n-1);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int arr[]={1,5,6};
    int sum=7;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<solve(arr,sum,n)<<endl;
    return 0;
}
/*
Time Complexity: O(n*m)
Space complexity :O(n*m)
*/











// // Maximum number of way to make given sum
#include<bits/stdc++.h>
using namespace std;


int CountCoin(int coin[] ,int sum,int n)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coin[i-1]<=j)
            {
                //       current     previous max value of 
                //     of mx-change  of that coin
                dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }

    }
    
    return dp[n][sum];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int coin[] = {2,3,4,5,6,7,8,9,10};
    int sum= 10;
    int n=sizeof(coin)/sizeof(coin[0]);
    cout<<"Maximum ways to change coin :"<<CountCoin(coin,sum,n)<<"\n";
    return 0; 
}
/* 
Time Complexity: O(n*m)
Space complexity :O(n*m)
*/




/*


for printing the coins

class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {


            // for no infinite coins
            if(i && candidates[i]==candidates[i-1] && i>begin) continue;
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i+1);
            combination.pop_back();



            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
*/








/*

The auxiliary space required here is O(n) only. 


int count( int S[], int m, int n )		
{		
    // table[i] will be storing the number of solutions for		
    // value i. We need n+1 rows as the table is constructed		
    // in bottom up manner using the base case (n = 0)		


    int table[n+1];		
    
    // Initialize all table values as 0		
    memset(table, 0, sizeof(table));		
    
    
    // Base case (If given value is 0)		
    table[0] = 1;


    // Pick all coins one by one and update the table[] values		
    // after the index greater than or equal to the value of the		
    // picked coin	
    	
    for(int i=0; i<m; i++)		
    for(int j=S[i]; j<=n; j++)		
    table[j] += table[j-S[i]];		
    return table[n];		
}		

*/

































// Another Way optimise

/*
#include <iostream>
#include <climits>
using namespace std;

int coinsExchange(int amt, int *deno, int n, int *dp) {
	// base case
	if (amt == 0) {
		return dp[amt] = 0;
	}
	if (dp[amt] != -1) {
		return dp[amt];
	}

	// recursive case
	int ans = INT_MAX;
	for (int i = 0 ; i < n ; i++) {
		if (amt >= deno[i]) {
			int sa = coinsExchange(amt - deno[i], deno, n, dp);
			if (sa != INT_MAX) {
				ans = min(sa + 1, ans);
			}
		}
	}

	return dp[amt] = ans;
}

int main() {

	int deno[4] = {1, 2, 5, 10};
	int amt = 50;
	int *dp = new int[amt + 1];
	for (int i = 0 ; i <= amt ; i++) {
		dp[i] = -1;
	}
	cout << coinsExchange(amt, deno, 4, dp) << endl;

	return 0;
}


O(m*n)
*/