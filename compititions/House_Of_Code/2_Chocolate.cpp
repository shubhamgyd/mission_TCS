#include<bits/stdc++.h>
using namespace std;

int solve(int k, int s, int i, vector<vector<int>>&dp){
    if(i==3 && s==0){
        return 1;
    }
    if(s==0){
        return 1;
    }
    if(s<0 || i>=3){
        return 0;
    }
   
    if(dp[s][i]!=-1){
        return dp[s][i];
    }
    int op = 0;
    for(int indx=0; indx<=k; indx++){
        op += solve(k,s-indx,i+1,dp);
    }
    return dp[s][i] = op;
}


int main(){
    int k;
    cin>>k;
   
    int s;
    cin>>s;
   
    vector<vector<int>>dp(s+1,vector<int>(4,-1));
    cout<<solve(k,s,0,dp);
}