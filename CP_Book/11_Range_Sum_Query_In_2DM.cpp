// In this problem we are going to find the range sum query in 2d matrix

// The intution behind this is finding the sum till k'th ans store in table
// formula to finding this sum is S(A) -S(B) - S(C) - S(D)
// Where S(A)==endpoint of subgrid , S(D) = Starting point of subgrid , S(C)and S(B) are remainin two points

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    //int a1,a2,b1,b2,c1,c2,d1,d2;
    //cin>>a1>>a2>>b1>>b2>>c1>>c2>>d1>>d2;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<endl;
    int dp[n][n];
    dp[0][0]=arr[0][0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0&&j==0)
            {
                continue;
            }
            else if(j==0 && i!=0)
            {
                dp[i][j]=dp[i-1][n-1]+arr[i][j];
            }
            else dp[i][j]=dp[i][j-1]+arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<(dp[d1-1][d2-1]+dp[a1-1][a2-1])-(dp[b1-1][b2-1]+dp[c1-1][c2-1])<<endl;

}