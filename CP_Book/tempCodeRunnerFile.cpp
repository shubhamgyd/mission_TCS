#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define int long long 




int32_t main(){
    vector<int>res;
    for(int i=0;i<10;i++)
    {
        res.push_back(i);
    }
    vector<int>temp(res.begin()+0,res.begin()+2+1);
    for(auto it:temp)
    {
        cout<<it<<" ";
    }
    return 0;
}