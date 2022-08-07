#include<bits/stdc++.h>
using namespace std;

int solve(int i,vector<int>&res,int isStart)
{
    if(i>=res.size()) return 0;
    int include=0;
    int exclude=0;
    
}

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    if(n==2)
    {
        cout<<2<<endl;
        return 0;
    }
    int ans=solve(0,res,1);
    return 0;
}