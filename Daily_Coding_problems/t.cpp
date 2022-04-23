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
const int mod=1e9+7;





void solve()
{
   string str;
   getline(cin,str);
   stringstream ss(str);
   string word;
   int pair=0;
   int it=0;
   while(ss>>word)
   {
        if(word=="pair")
        {
            pair++;
        }
        else
        {
            it++;
        }
   }
   if(it-pair!=1)
   {
        cout<<"Error occurred"<<endl;
   }
   else
   {
        string s=",int>";
        while(pair--)
        {
            cout<<"pair<";
        }
        cout<<"int";
        it--;
        while(it--)
        {
            cout<<s;
        }
        cout<<endl;
   }

}




signed main()
{
// #ifndef ONLINE_JUDGE
//         freopen("inputf.in", "r", stdin);
//         freopen("outputf.out", "w", stdout);
// #endif
    // fast();
    // int t;
    // cin >> t;
    // int temp=t;
    // while(t--)
    // {
    //     solve(temp);
    // }
    // int n;
    // cin>>n;
    solve();
    
    return 0;
}