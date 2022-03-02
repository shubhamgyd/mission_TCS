#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
using namespace std;
#define endl '\n'
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define all(a) a.begin(), a.end()
#define pi 3.141592653
#define pb push_back
#define mp make_pair



void solve()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int time=0;
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        int num1=res[i];
        int num2=res[j];
        time+=max(num1,num2);
        if(num1==num2)
        {
            i++;
            j--;
            continue;
        }
        if(num1>num2)
        {
            int rem=num1-num2;
            j--;
            while(j>=0)
            {
                if(rem>=res[j])
                {
                    
                    rem-=res[j];
                    res[j]=0;
                    j--;
                }
                else
                {
                    res[j]-=rem;
                    break;
                }
            }
            i++;
        }
        if(num1<num2)
        {
            int rem=num2-num1;
            i++;
            while(i<n)
            {
                if(rem>=res[i])
                {

                    rem-=res[i];
                    res[i]=0;
                    i++;
                }
                else
                {
                    res[i]-=rem;
                    break;
                }
            }
            j--;
        }

    }
    cout<<time<<endl;
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