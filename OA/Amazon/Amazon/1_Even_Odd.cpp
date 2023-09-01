// #include<bits/stdc++.h>
// using namespace std;
// #define int long long 

// namespace Own
// {
//     class Solution
//     {
//     public:
//         void solve(int num)
//         {
//             vector<int>res;
//             while(num>0)
//             {
//                 res.push_back(num%10);
//                 num/=10;
//             }
//             sort(res.begin(),res.end());
//             int num1=0;
//             int num2=0;
//             for(int i=0;i<res.size();i++)
//             {   
//                 if(i%2==0) num1=num1*10+res[i];
//                 else num2=num2*10+res[i];
//             }
//             cout<<num1+num2<<endl;
//         }
//     };
// }

// int32_t main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         Own::Solution obj;
//         obj.solve(n);
//     }
//     return 0;
// }



#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
using namespace std;




int CountCoin(vector<int>coin ,int sum,int n)
{
    int dp[n+1][sum+1];

    for(int i=0;i<=n;i++)  
    {
        dp[i][0]=0;                    
    }
    for(int i=1;i<=sum;i++) 
    {
        dp[0][i]=INT_MAX-1;     
    }

    for(int j=1;j<=sum;j++)  
    {
        
        if(j%coin[0]==0)
            dp[1][j]=j/coin[0];
        else
            dp[1][j]=INT_MAX-1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coin[i-1]<=j)
            {
                dp[i][j]=min((dp[i][j-coin[i-1]]+1),dp[i-1][j]); 
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }

    }
    if(dp[n][sum]==INT_MAX-1) return -1; 
    return dp[n][sum];
}

int32_t main()
{
// #ifndef ONLINE_JUDGE
//     freopen("inputf.in", "r", stdin);
//     freopen("outputf.out", "w", stdout);
// #endif
    fast();
    int n;
    cin>>n;
    vector<int>res;
    for(int i=1;i<=n;i++)
    {
        int num=sqrt(i);
        if(num*num==i)
        {
            res.push_back(i);
        }
    }

    cout<<CountCoin(res,n,res.size())<<endl;
    return 0;
}