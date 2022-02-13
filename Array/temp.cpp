#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
// #define mod 1000000007
using namespace std;
#define endl '\n'



void solve()
{
    int n;
    cin>>n;
    vector<int>res(2*n);
    vector<int>first,second;
    for(int i=0;i<2*n;i++)
    {
        cin>>res[i];
        if(i<n)
        {
            first.push_back(res[i]);
        }
        else
        {
            second.push_back(res[i]);
        }
    }
    int mx1=0;
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    int i=0;
    for(;i<first.size();)
    {
        if(first[i]!=mx1)
        {
            break;
        }
        else if(mx1==first[i])
        {
            mx1++;
            int j=i;
            while(j<first.size() && first[i]==first[j])
            {
                j++;
            }
            i=j;
        }
    }
    if(first.back()==mx1)
    {
        mx1++;
    }
    int  mx2=0;
    i=0;
    for(;i<second.size();)
    {
        if(second[i]!=mx2)
        {
            break;
        }
        else if(mx2==second[i])
        {
            mx2++;
            int j=i;
            while(j<second.size() && second[i]==second[j])
            {
                j++;
            }
            i=j;
        }
    }
    if(second.back()==mx2)
    {
        mx2++;
    }

    if(mx1==mx2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    
}

int32_t main()
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