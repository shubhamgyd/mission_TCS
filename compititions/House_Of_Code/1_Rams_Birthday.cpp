#include<bits/stdc++.h>
using namespace std;
int main (){
    int n,k;
    cin>>n>>k;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int m=0;
    for(int i=0;i<n-2;i++){
        sort(v.begin()+i,v.end());
        int diff=abs(v[i+1]-v[i+2]);
        if(diff>k){
            m++;
        }
    }
    cout<<m<<endl;
    return 0;
}