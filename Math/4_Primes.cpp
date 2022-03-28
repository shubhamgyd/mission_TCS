#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;

int main()
{

    int is_prime[MAXN];
    for(int i=0;i<MAXN;i++)
    {
        is_prime[i]=1;
    }
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i<MAXN;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<MAXN;j+=i)
            {
                is_prime[j]=0;
            }
        }
        // to avoid overflow
        if(i*i>MAXN)
        {
            break;
        }
    }
    int ct=0;
    for(int i=0;i<MAXN;i++)
    {
        if(is_prime[i])
        {
            ct++;
        }
    }
    cout<<ct<<endl;
    return 0;
}
// Time Complexity:O(nloglog(n))