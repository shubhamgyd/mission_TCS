#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long


struct Result
{
    Result():output1(){};
    int  output1[100];
};

struct Result solve(int n,int k,vector<int>&res)
{
    int val;
    for(int i=0;i<n;i++)
    {
        if(i==k-1)
        {
            val=res[i];
            res.erase(res.begin()+i);
        }
    }
    res.insert(res.begin()+0,val);
    return res;
}

int32_t main()
{
    int n,k;
    cin>>n>>k;
    vector<int>res;
    int val=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
    }
    vector<int>ans=solve(n,k,res);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
