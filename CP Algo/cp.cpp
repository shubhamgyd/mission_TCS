#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long 
#define mod 1000000007
using namespace std;
#define endl '\n'

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int flag=0;
        int low=1;
        int high=cbrt(n);
        while(low<=high)
        {
            int val=(low*low*low+high*high*high);
            if(val==n)
            {
                cout<<"YES"<<endl;
                flag=1;
                break;
            }
            if(val<n)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        if(!flag)
        {
            cout<<"NO"<<endl;
        }

    }
    return 0;
}
