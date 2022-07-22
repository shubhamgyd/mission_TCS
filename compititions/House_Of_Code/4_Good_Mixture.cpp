#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n, m;
set<pair<ll, ll>>st;
int ans = 0;

void recursion(ll i, set<ll>&ds)
{
    if (i > n)
    {
        if (ds.empty())ans++;
        else
        {
            for (auto it : st)
            {
                if (ds.count(it.first) && ds.count(it.second))return;
            }
            ans++;
        }
        return;
    }
    recursion(i + 1, ds);
    ds.insert(i);
    recursion(i + 1, ds);
    ds.erase(i);
}



void solve()
{

    cin >> n >> m;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        st.insert({a, b});
    }
    set<ll>ds;
    recursion(1, ds);
    cout << ans << endl;


}