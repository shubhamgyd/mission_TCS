#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&res,int i,int j,int &mn,int &mx)
{
    // base case: Only one number
    if(i==j)
    {
        mn=res[i];
        mx=res[j];
    }
    else
    {
        int mid=(i+j)/2;
        int lmin,lmx;
        int rmin,rmax;
        solve(res,i,mid,lmin,lmx);
        solve(res,mid+1,j,rmin,rmax);

        mn=lmin<rmin?lmin:rmin;
        mx=lmx>rmax?lmx:rmax;
    }
}
// we are visiting each element only once,
// Time Complexity:O(n)
// Space Complexity:O(1)


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int mn=INT_MAX;
    int mx=0;
    solve(res,0,n-1,mn,mx);
    cout<<mn<<" "<<mx<<endl;
    return 0;
}