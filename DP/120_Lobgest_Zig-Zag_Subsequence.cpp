
#include<bits/stdc++.h>
using namespace std;


int ZigZagLength(vector<int>&res)
{
    int n=res.size();
    int dp[n][2];   // dp[n][0] indicates last elemet is greate than its previous
                    // where dp[n][1] indicates last element is smaller than it's previous

    // Base condition , initially defualt length is 1
    for(int i=0;i<n;i++)
    {
        dp[i][0]=dp[i][1]=1;
    }

    int mx=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(res[i]>res[j] && dp[i][0]<dp[j][1]+1)
            {
                dp[i][0]=dp[j][1]+1;
            }

            if(res[i]<res[j] && dp[i][1]<dp[j][0]+1)
            {
                dp[i][1]=dp[j][0]+1;
            }
        }
        if(mx<max(dp[i][0],dp[i][1]))
        {
            mx=max(dp[i][0],dp[i][1]);
        }
    }
    return mx;
}
// Time Complexity :O(n*n)
// Space Complexity :O(n)







int Length(vector<int>&arr)
{
    int n=arr.size();

    int inc[n];
    int desc[n];

    inc[0]=desc[0]=1;

    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            inc[i]=desc[i-1]+1;
            desc[i]=desc[i-1];
        }
        else if(arr[i]<arr[i-1])
        {
            desc[i]=inc[i-1]+1;
            inc[i]=inc[i-1];
        }
        else
        {
            desc[i]=desc[i-1];
            inc[i]=inc[i-1];
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout<<inc[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<desc[i]<<" ";
    // }
    // cout<<endl;
    return max(inc[n-1],desc[n-1]);
}
// Time Complexity :O(n)
// Space Complexity :O(n)





int Length1(vector<int>&arr)
{
    int n=arr.size();



    int inc=1,desc=1;


    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            inc=desc+1;
            desc=desc;
        }
        else if(arr[i]<arr[i-1])
        {
            desc=inc+1;
            inc=inc;
        }
        else
        {
            inc=inc;
            desc=desc;
        }
    }
    return max(inc,desc);
}
// Time Complexity :O(n)
// Space Complexity :O(1)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
    }

    cout<<ZigZagLength(res)<<endl;
    cout<<Length(res)<<endl;
    cout<<Length1(res)<<endl;
    return 0;
}