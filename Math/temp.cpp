#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int  long long 
using namespace std;
#define endl '\n'
#define max_pq priority_queue<int>
#define min_pq priority_queue<int,vector<int>,greater<int>>
#define For(i,x,n) for(i=x; i<n; ++i)
#define pb push_back
const int mod=32768;

int test=1;

int Operations(int a)
{
    cout<<a<<endl;
    if(a==0){
        return INT_MAX;
    }
    if(a==mod)
    {
        return INT_MAX;
    }
    if(a>mod)
    {
        a=a%mod;
    }
    // int a1=Operations((a+1)%mod);
    // int a2=Operations((a*2)%mod);
    return 1+min(Operations((a+1)),Operations((a*2)));
    // return 1+min(a1,a2);
}


const int mod = 32768;
double begintime, endtime;

using namespace std;

int n, x, a[mod+8];
vector<int>l[mod+8];
queue<int>s;
int main()
{
    
   // ios_mod::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(a, -1, sizeof(a));
    for(int i = 0; i < mod; i++)
    {
        l[(i+1)%mod].push_back(i);
        l[(i*2)%mod].push_back(i);
    }
    a[0] = 0;
    s.push(0);
    while(!s.empty())
    {
        x = s.front();
        s.pop();
        for(int tmp : l[x])
            if(a[tmp] == -1)
            {
                a[tmp] = a[x]+1;
                s.push(tmp);
            }
    }
    cin>>n;
    while(n--)
    {
        cin>>x;
        cout<<a[x]<<' ';
    }
    return 0;
}

void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        cout<<a<<endl;
        int ans=Operations(a);
        cout<<ans<<endl;
    }


}



signed main()
{
// #ifndef ONLINE_JUDGE
//         freopen("inputf.in", "r", stdin);
//         freopen("outputf.out", "w", stdout);
// #endif
    fast();
    // int t;
    // cin >> t;
    // while(t--)
    // {
    //     solve();
    // }
    solve();
    
    return 0;
}