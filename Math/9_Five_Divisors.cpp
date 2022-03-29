#include<bits/stdc++.h>
using namespace std;

const long long int mx=1e18;
vector<long long>primes(10000,1);

set<long long>bucket;

void Primes()
{
    primes[0]=primes[1]=0;
    for(int i=1;i<=10000;i++)
    {
        if(primes[i])
        {
            for(int j=i*i;j<=10000;j+=i)
            {
                primes[j]=0;
            }
        }
    }
    for(int i=1;i<=10000;i++)
    {
        if(primes[i])
        {
            if(mx>=i*i*i*i)
            {
                bucket.insert(i*i*i*i);
            }
        }
    }
}
// Time Complexity:O(NLogN)


int main()
{
    Primes();
    int n;
    cin>>n;
    if(bucket.find(n)!=bucket.end())
    {
        cout<<"Yes given number have 5 divisors..."<<endl;
    }
    else
    {
        cout<<"Given number don't have 5 divisors"<<endl;
    }

    return 0;
}