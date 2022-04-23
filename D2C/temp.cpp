#include<bits/stdc++.h>
using namespace std;
#define int long long

int backbencherAndBugs(int n,vector<int>&nums)
{
    int questions=0;
    int total_ways=0;
    if(n==1)
    {
        return nums[0];
    }
    for(int i=0;i<n;i++)
    {
        total_ways+=nums[i];
        total_ways+=questions*(nums[i]-1);
        questions++;
    }
    return total_ways;
}



signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                    
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            cin>>res[i];
        }
        int ans=backbencherAndBugs(n,res);
        cout<<ans<<endl;
    }
    return 0;
}