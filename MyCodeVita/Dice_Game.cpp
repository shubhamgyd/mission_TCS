#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int  unsigned long long int
using namespace std;
#define endl '\n'
const int mod=1e9+7;
#define max_pq priority_queue<int>
#define min_pq priority_queue<int,vector<int>,greater<int>>
#define For(i,x,n) for(i=x; i<n; ++i)
#define pb push_back




void Solution()
{
    int CoinWays[100005];
    memset(CoinWays,0,sizeof(CoinWays));
    int sum,coins;
    cin>>sum>>coins;
    vector<int>store(coins);
    for(int i=0;i<coins;i++) { store[i]=i+1;}
    CoinWays[0]=1;
    for (int j = 0; j <= sum; j++) {
        for (int i = 1; i <= coins; i++) {
            if(j>=store[i - 1]){ 
                CoinWays[j] += CoinWays[j - store[i - 1]];
            }
        }
    }
    cout<<CoinWays[sum]<<endl;
}

signed main()
{
    fast();
    int t;
    cin>>t;
    while(t--)
    {
        Solution();
    }
}

