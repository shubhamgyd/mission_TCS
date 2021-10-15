#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long



int Val(int arr[],int n)
{
    int inc[n];
    int dec[n];
    memset(inc,0,sizeof(inc));
    memset(dec,0,sizeof(dec));
    inc[0]=dec[0]=arr[0];

    int flag=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[i])
            {
                dec[i]=max(dec[i],inc[j]+arr[i]);
                flag=1;
            }
            else if(arr[j]<arr[i] && flag==1)
            {
                inc[i]=max(inc[i],dec[j]+arr[i]);
            }
        }
    }

    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=max(dec[i],inc[i]);
    }
    return sum;
}
// Time Complexity :O(n*n)
// Space Complexity :O(n)

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    int arr[]={ 8, 2, 3, 5, 7, 9, 10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<Val(arr,n)<<endl;
    return 0;
}


