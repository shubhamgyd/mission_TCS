
#include <bits/stdc++.h>
using namespace std;
int dp[101][101][2];  // Row col dir

int Formulate(int k,int i,int j,int flag,int prev)
{
    if(i>2 || j>2)
    {
        return 0;
    }

    if(dp[i][j][prev]>=0)
    {
        return dp[i][j][prev];
    }

    if(k>=0 && i==2 && j==2)
    {
        return 1;
    }

    if(k<0 && (i!=2 && j!=2) )
    {
        return 0;
    }

    if(prev)
    {
        return dp[i][j][prev]=Formulate(k,i+1,j,1,prev)+Formulate(k-1,i,j+1,0,!prev);
    }
    else
    {
        return dp[i][j][prev]=Formulate(k-1,i+1,j,1,!prev)+Formulate(k,i,j+1,0,prev);
    }
}



// DP Solution
int CountWays(int m,int n,int k)
{
    int dp[10][10][10][2]={{{{0}}}}; // For dp[row][col][turn][dir];
    // Direction=0 --> Paths in horizantal direction
    // Direction=1 --> Paths in vertical direction


    // Number of ways to comming ith column horizantaly
    for(int i=1;i<n;i++)
    {
        dp[0][i][0][0]=1;
    }


    // Number of ways to coming ith row vertically
    for(int j=1;j<m;j++)
    {
        dp[j][0][0][1]=1;
    }


    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            // Paths with no change in direction
            for(int turns=0;turns<=k;turns++)
            {
                // i , j will give the same number of vertical paths with same number of turns
                dp[i][j][turns][1]+=dp[i-1][j][turns][1];


                //i ,j  will have the same number of horizantal paths with same number of turns
                dp[i][j][turns][0]+=dp[i][j-1][turns][0];


                // Horizantl to vertical paths add turn
                dp[i][j][turns+1][1]+=dp[i-1][j][turns][0];


                // Vertical to horizantal paths add turn
                dp[i][j][turns+1][0]+=dp[i][j-1][turns][1];
            }
        }
    }


    int sum=0;
    for(int i=0;i<=k;i++)
    {
        sum+=dp[m-1][n-1][i][0];
        sum+=dp[m-1][n-1][i][1];
    }

    return sum;
}
// Time Complexity :O(m*n*k)
// Space Complexity :O(10*10*10*2)


int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n,m,k;
    cin>>n>>m>>k;
    int prev=1;
    int i=0,j=0;
    memset(dp,-1,sizeof(dp));
    cout<<Formulate(k,i+1,j,1,prev)+Formulate(k,i,j+1,0,!prev)<<endl;
    cout<<CountWays(m,n,k)<<endl;
	return 0;
}