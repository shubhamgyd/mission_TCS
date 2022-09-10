#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>nums(n,vector<int>(2));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>nums[i][j];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        int cnt=0;
        for(int i=l;i<=r;i++)
        {
            if(nums[i][1]>x) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}