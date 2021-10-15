#include<bits/stdc++.h>
using namespace std;

int RodCut(int prices[],int n,int length[],int max_len)
{
    int rod[n+1][max_len+1];
    // The maximum priceue will be zero,
    // when either the length of the rod
    // is zero or price is zero.
    if(n==0 || max_len==0) return 0;

    // If the length of the rod is less
    // than the maximum length, Max_lene will
    // consider it.Now depending 
    // upon the profit,
    // either Max_lene  we will take 
    // it or discard it.
    if(length[n-1]<=max_len)
    {
        rod[n][max_len]=max(prices[n-1]+RodCut(prices,n,length,max_len-length[n-1]),
                               RodCut(prices,n-1,length,max_len));
    }

    // If the length of the rod is
    // greater than the permitted size,
    // Max_len we will  not consider it.
    else
    {
        rod[n][max_len]=RodCut(prices,n-1,length,max_len);
    }

    return rod[n][max_len];
    
}

int RodCut1(int prices[],int n,int length[],int max_len)
{
    int tab[n+1][n+1];
    // for(int i=0;i<n;i++)
    // {
    //     tab[i][0]=0;
    // }
    // for(int i=0;i<n;i++)
    // {
    //     tab[0][1]=0;
    // }
    memset(tab,0,sizeof(tab));
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         if(i==0) tab[i][j]=0;
    //         if(j==0) tab[i][j]=0;
    //     }
    // }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j-length[i-1]>=0)
            {
                tab[i][j]=max(prices[i-1]+tab[i][j-length[i-1]],tab[i-1][j]);
            }
            else
            {
                tab[i][j]=tab[i-1][j];
            }
        }
    }
    return tab[n][n];
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int prices[]={1, 5, 8, 9, 10, 17, 17, 20 };
    int n=sizeof(prices)/sizeof(prices[0]);
    int length[n];
    for(int i=0;i<n;i++)
    {
        length[i]=i+1;
    }
    int max_len=n;
    cout<<" Maximum Profit after cutting rod: "<<RodCut1(prices,n,length,max_len)<<"\n";
    return 0; 
}