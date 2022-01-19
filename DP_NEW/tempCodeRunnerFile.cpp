#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long 
#define mod 1000000007
using namespace std;
#define endl '\n'


int32_t main()
{
// #ifndef ONLINE_JUDGE
//     freopen("inputf.in", "r", stdin);
//     freopen("outputf.out", "w", stdout);
// #endif
    fast();
    int n,ans;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
        if(i==0)
        {
            ans=a;
        }
        else
        {
            ans=__gcd(ans,a);
        }
    }
    // cout<<ans<<endl;
    while(ans%2==0) ans/=2;
    while(ans%3==0) ans/=3;
    // cout<<ans<<endl;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        int ct1=1,ct2=1;
        while(res[i]%(ct1*2)==0) 
        {
            cout<<"two"<<endl;
            ct1*=2;
        }
        while(res[i]%(ct2*3)==0) 
        {
            cout<<"Three"<<endl;
            ct2*=3;
        }
        if(ans*ct1*ct2!=res[i])
        {
            cout<<"No"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"Yes"<<endl;
    }
    return 0;
}