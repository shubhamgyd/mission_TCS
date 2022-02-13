#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;

long long findFact(int num)
{
    int i=1, fact=1;
    while(i<=num)
    {
        fact = i*fact;
        i++;
    }
    return fact;
}

int findNPR(int n, int r)
{
    long long numerator, denominator;
    numerator = findFact(n);
    denominator = findFact(n-r);
    return (numerator/denominator);
}


int findNCR(int n, int r)
{
    int npr, ncr;
    npr = findNPR(n, r);
    ncr = npr/findFact(r);
    return ncr;
}

int zeroSubsequences(vector<int>arr)
{
    int n=arr.size();
    int lesser=0,greater=0;
    long long ct=0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            ct++;
        }
        if(arr[i]<0)
        {
            lesser++;
        }
        else if(arr[i]>0)
        {
            greater++;
        }
    }
    if(ct>1)
    {
        int temp=ct-1;
        // lesser+=temp;
        // greater+=temp;
    }
    long long ans=0;
    // long long temp=0;
    if(ct)
    {
        for(int i=0;i<lesser+ct-1;i++)
        {
            ans=(ans%mod+(findNPR(lesser+ct-1,i+1)))%mod;
            // temp=(temp%mod+(findNCR(lesser+ct-1,i+1)))%mod;
        }
        for(int i=0;i<greater+ct-1;i++)
        {
            ans=(ans%mod+(findNPR(greater+ct-1,i+1)))%mod;
            // temp=(temp%mod+(findNCR(greater+ct-1,i+1)))%mod;
        }
        
        // ans=((ans%mod)*(ct%mod))%mod;
    }
    if(ct==1)
    {
        ans=(ans%mod+1LL%mod)%mod;
        // temp=(temp%mod+1LL%mod)%mod;
    }
    // cout<<ans<<" "<<temp<<endl;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<zeroSubsequences(arr)<<endl;
    return 0;
}