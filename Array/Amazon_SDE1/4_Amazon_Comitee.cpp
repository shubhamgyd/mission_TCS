#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main()
{
    int n;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
    }

    int associations;
    cin>>associations;

    int mn,mx;
    cin>>mn>>mx;

    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(res[i]>=mn && res[i]<=mx)
        {
            ans.push_back(res[i]);
        }
    }
    int total=0;
    for(int i=associations;i<=ans.size();i++)
    {
        n=ans.size();
        int r=i;
        if (r > n)
        {
            total+=0;
            continue;
        }
        int m = 1000000007;
        int inv[r + 1] = { 0 };
        inv[0] = 1;
        if(r+1>=2)
        inv[1] = 1;
        for (int i = 2; i <= r; i++) {
            inv[i] = m - (m / i) * inv[m % i] % m;
        }
    
        int num = 1;
    
        for (int i = 2; i <= r; i++) {
            num = ((num % m) * (inv[i] % m)) % m;
        }
    
        for (int i = n; i >= (n - r + 1); i--) {
            num = ((num % m) * (i % m)) % m;
        }
        total+=num;
    }
    cout<<total<<endl;
    return 0;
}