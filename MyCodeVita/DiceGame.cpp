#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef unsigned long long ull;
typedef long long int ll;
#define endl "\n"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define max_pq priority_queue<int>
#define min_pq priority_queue<int,vector<int>,greater<int>>
#define For(i,x,n) for(i=x; i<n; ++i)
#define pb push_back
const long long int mod = 1000000007;
using namespace std;
 
long long int CountWays(int sum, int mFaces) {
    vector<long long> Ways(100005, 0);
    Ways[0] = 1;
    for (int i=0; i<=sum; i++) {
        for (int j=1; j<=mFaces; j++) { 
            Ways[i + j] += Ways[i];
        }
    }
    return Ways[sum];
}
 
int32_t main()
{
    fast();
    int t;
    cin>>t;
    while (t--) {
        ll sum, mFaces; cin>>sum>>mFaces;
        int ans=CountWays(sum,mFaces);
        cout<<ans<<endl;
    }
}