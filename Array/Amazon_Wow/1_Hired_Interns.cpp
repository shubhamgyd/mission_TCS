#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    long long k;
    cin>>k;
    int cnt = 1;
    int res = 5000;
    if(k % res == 0)
    {
        cout << k/res << endl;
    }
    else
    {
        while(res%10 != k%10)
        {
            res = res + 5000 + cnt;
            cnt++;
        }
        cout << (k-res)/5000 + 1 <<endl;
    }    
}