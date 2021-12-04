#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

template<size_t m,size_t n>
int MinPathSum(int arr[][m][n],int l)
{
    if(l==0 || m==0 || n==0)
    {
        return 0;
    }

    // Use given matrix as a dp table
    for(int i=l-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            for(int k=n-1;k>=0;k--)
            {
                int v1=i==l-1?INT_MAX:arr[i+1][j][k];
                int v2=j==m-1?INT_MAX:arr[i][j+1][k];
                int v3=k==n-1?INT_MAX:arr[i][j][k+1];
                int mn=min({v1,v2,v3});
                if(mn!=INT_MAX)
                {
                    arr[i][j][k]+=mn;
                }
            }
        }
    }


    int sum=arr[0][0][0];
    // to stre the output

    // now retrive the output
    for(int i=l-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            for(int k=n-1;k>=0;k--)
            {
                int v1=i==l-1?INT_MAX:arr[i+1][j][k];
                int v2=j==m-1?INT_MAX:arr[i][j+1][k];
                int v3=k==n-1?INT_MAX:arr[i][j][k+1];
                int mn=min({v1,v2,v3});
                if(mn!=INT_MAX)
                {
                    arr[i][j][k]-=mn;
                }
            }
        }
    }

    return sum;

}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    int arr[][2][2]= { {{1, 2}, {3, 4}},
                     {{4, 8}, {5, 2}} };
                     
    cout<<MinPathSum(arr,2)<<endl;    
	return 0;
}
