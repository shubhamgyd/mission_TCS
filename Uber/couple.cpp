#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
using namespace std;
#define endl '\n'





void solve()
{
    
    int n,k;
    cin>>n>>k;
    vector<int>res(k);
    for(int i=0;i<k;i++)
    {
        cin>>res[i];
    }
    if(k==n)
    {
        for(auto it:res)
        {
            cout<<it<<" ";
        }
        return;
    }
    map<int,int>mp;
    for(auto it:res)
    {
        mp[it]++;
    }
    int i=1;
    while(i<=n)
    {
        if(mp.find(i)==mp.end())
        {
            res.push_back(i);
            i++;
        }
        else
        {
            continue;
        }
    }
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    cout<<endl;


}


signed main()
{
// #ifndef ONLINE_JUDGE
//         freopen("inputf.in", "r", stdin);
//         freopen("outputf.out", "w", stdout);
// #endif
    fast();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
    return 0;
}