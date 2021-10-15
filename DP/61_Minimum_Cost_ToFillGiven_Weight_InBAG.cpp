/*
Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges,
 the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output 
 will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
2. It may be assumed that there is infinite supply of all available packet types.
*/

// Big Hint:  Think about Unbounded Knapsack


#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        int size=0;
        vector<int>val,wt;

        // Here we can't take negative value  , i.e means value only positive
        
        // traverse the original cost[] array and skip
        // unavailable packets and make val[] and wt[]
        // array. size variable tells the available number
        // of distinct weighted packets.
        for(int i=0;i<N;i++)
        {
            if(cost[i]!=-1)
            {
                val.push_back(cost[i]);
                wt.push_back(i+1);
                size++;
            }
        }
        N=size;// Resize the value of N , i.e updated value

        // Create a table of size N+1 and W+1 
        int dp[N+1][W+1];

        // fill 0th row with infinity
        for(int j=0;j<=W;j++)
        {
            dp[0][j]=INF;
        }
        // fill 0th col with 0
        for(int i=1;i<=N;i++)
        {
            dp[i][0]=0;
        }


        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=W;j++)
            {
                // wt[i-1]>j means capacity of bag is
                // less then weight of item
                //Means we can't add it into the bag ,so its weight value becomes the , previous value(whose weight is less than bag capacity)
                if(wt[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }

                // here we check we get minimum cost either
                // by including it or excluding it
                // Excuding: dp[i-1][j]
                // Including : val[i-1]+dp[i][j-wt[i-1]]
                else
                {
                    dp[i][j]=min(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
                }
            }
        }
        // exactly weight W can not be made by given weights
        return (dp[N][W]==INF)? -1: dp[N][W];
	} 
};

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  