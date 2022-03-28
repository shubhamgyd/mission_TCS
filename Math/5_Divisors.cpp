#include<bits/stdc++.h>
using namespace std;

void fill_divisors(int n)
{
    int cnt[n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            cnt[j]++;
        }
    }
}
// Time Complexity:O(nlogn)
// Space Complexity:O(n)





int main()
{
    int n;
    cin>>n;
    int ct=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            ct++;
            // think about perfect square
            if(n/i!=i)
            {
                ct++;
            }
        }
    }
    cout<<ct<<endl;
    return 0;
}
// Time Complexity:O(root n)