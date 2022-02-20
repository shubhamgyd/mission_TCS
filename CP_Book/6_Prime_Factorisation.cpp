// In this program we are going to see the prime factorisation of a number
#include<bits/stdc++.h>
using namespace std;
#define int long long int

set<int> factors(int n) {
    set<int> f;
    for (int x = 2; x*x <=n; x++) 
    {
        while (n%x == 0) 
        {
            cout<<x<<" ";
            f.insert(x);
            n /= x;
        }
    }
    if (n > 1) f.insert(n);
    return f;
}

int SumPrimeFactors(int n)
{
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    set<int>v=factors(n);
    int sum=0;
    for(auto it:v)
    {
        sum+=it;
    }
    cout<<"sum of prime is: "<<sum<<endl;
    return sum;
}

signed main()
{

    // for(int i=101;i<=200;i++)
    // {
    
    int n;
    cin>>n;
    SumPrimeFactors(n);
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    set<int>v=factors(n);
    // sort(v.begin(),v.end());
    int sum=0;
    for(auto it:v)
    {
        sum+=it;
    }
    cout<<sum<<endl;
    // cout<<endl;
    // set<int>st;
    // for(int i=0;i<v.size();i++)
    // {
    //     if(st.find(n-v[i])!=st.end())
    //     {
    //         //return {v[i],n-v[i]};
    //         cout<<v[i]<<" "<<n-v[i]<<endl;
    //         break;
    //     }
    //     st.insert(v[i]);
    // }
    // return {};
    //}
    return 0;
}