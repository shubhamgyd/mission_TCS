#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        // int mx=0;
        // vector<int>ev,od;
        // for(auto it:arr){
        // 	if(it%2==0) ev.push_back(it);
        // 	else od.push_back(it);
        // }
        // for(int i=0;i<ev.size();i++)
        // {
        // 	for(int j=0;j<od.size();j++)
        // 	{
        // 		mx=max(mx,(ev[i]+od[j])%k);
        // 	}
        // }
        // for(int i=0;i<ev.size();i++)
        // {
        // 	for(int j=i+1;j<ev.size();j++)
        // 	{
        // 		mx=max(mx,(ev[i]+ev[j])%k);
        // 	}
        // }
        // for(int i=0;i<od.size();i++)
        // {
        // 	for(int j=i+1;j<od.size();j++)
        // 	{
        // 		mx=max(mx,(od[i]+od[j])%k);
        // 	}
        // }
        // cout<<mx<<endl;
        unordered_set<int> ev;
        set<int> od;
        for (auto it : arr)
        {
            if (it % 2 == 0)
                ev.insert(it % k);
            else
                od.insert(it % k);
        }
        int mx = 0;
        for (auto it : ev)
        {
            int num = k - 1 - it;
            auto ele = od.upper_bound(num);
            if (ele != od.begin())

            {
                ele--;
                mx = max(mx, it + *ele);
            }
        }
        cout << mx << endl;
    }
    return 0;
}