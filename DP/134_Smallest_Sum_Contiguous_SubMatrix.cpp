#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

int Kadane(vector<int>&arr,int n)
{
    // int sum = 0, minSum = INT_MAX, i;
 
    // // Just some initial value to check for
    // // all negative values case
 
    // // local variable
    // int local_start = 0;
    
    // int finish=-1;
    // for (i = 0; i < n; ++i) {
    //     sum += arr[i];
    //     if (sum > 0) {
    //         sum = 0;
    //     } else if (sum < minSum) {
    //         minSum = sum;
    //     }
    // }
 
    // // There is at-least one non-negative number
    // if (finish != -1) {
    //     // cout<<minSum<<endl;
    //     return minSum;
    // }
 
    // // Special Case: When all numbers in arr[]
    // // are positive
    // minSum = arr[0];
    // for (i = 1; i < n; i++) {
    //     if (arr[i] < minSum) {
    //         minSum = arr[i];
    //     }
    // }
    // // cout<<minSum<<endl;
    // return minSum;


    int min_ending_here = INT_MAX;
    int min_so_far = INT_MAX;
    for (int i=0; i<n; i++)
    {
        if (min_ending_here > 0)
            min_ending_here = arr[i];
        else
            min_ending_here += arr[i];
        min_so_far = min(min_so_far, min_ending_here);           
    }
    return min_so_far;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    int n,m;
    cin>>n>>m;
    vector<vector<int>>res(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
        }
    }
    int mn=INT_MAX;
    for(int i=0;i<m;i++)
    {
        vector<int>v(n,0);
        for(int j=i;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                v[k]+=res[k][j];
            }
            mn=min(mn,Kadane(v,n));
            // cout<<mn<<endl;
        }
    }
    cout<<mn<<endl;
	return 0;
}
