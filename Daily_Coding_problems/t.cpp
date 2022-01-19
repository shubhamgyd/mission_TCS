#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long 
#define mod 1000000007
using namespace std;
#define endl '\n'


void solve()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string s;
        cin>>s;
        int hash[26];
        memset(hash,0,sizeof(hash));
        for(auto it:s)
        {
            hash[(it)-'0']++;
        }
        int len=0;
        for(int i=0;i<n;i++)
        {
            int flag=1;
            hash[str[i]-'0']--;
            for(int j=0;j<26;j++)
            {
                if(hash[i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                len=i+1;
                break;
            }
        }
        cout<<len<<endl;
    }
}



int32_t main() {
// #ifndef ONLINE_JUDGE
//     freopen("inputf.in", "r", stdin);
//     freopen("outputf.out", "w", stdout);
// #endif
    for(int i=-10;i++;)
    {
        cout<<"h"<<i<<endl;
    }
    return 0;
}