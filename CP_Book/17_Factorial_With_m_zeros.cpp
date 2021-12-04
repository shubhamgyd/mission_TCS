#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long



int find(int n)
{
    int count=0;
    for(int i=5;n/i>=1;i*=5)
    {
        count+=n/i;
    }
    // cout<<count<<endl;
    return count;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    int t=1;
    // cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        std::vector<int> res;
        for(int i=5;i<=400009;i++)
        {
            int zero=find(i);
            if(zero==a)
            {
                res.push_back(i);
            }
            else if(zero>a)
            {
                break;
            }
        }
        cout<<res.size()<<endl;
        for(auto it:res)
        {
            cout<<it<<" ";
        }

    }
	return 0;
}
