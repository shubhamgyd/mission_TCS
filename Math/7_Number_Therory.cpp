// Find the natural numbers which are almost prime
// means N=p1*p1 and p1!=p2 and p1 and p2 are primes
// N<=3000



#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int is_primes[n+1];
    for(int i=0;i<=n;i++)
    {
        is_primes[i]=1;
    }
    is_primes[0]=is_primes[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(is_primes[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                is_primes[j]=0;
            }
        }
    }

    int count=0;
    for(int i=2;i<=n;i++)
    {
        
            cout<<i<<endl;
            if(is_primes[i])
            {
                for(int j=i;j<=n;j+=i)
                {
                    // bool flag=false;
                    // if(is_primes[j])
                    // {
                    //     int num=i/j;
                    //         if(is_primes[num] && num*j==i && num!=j)
                    //         {
                    //             cout<<i<<"="<<j<<"*"<<num<<endl;
                    //             count++;
                    //             flag=true;
                    //             break;
                    //         }
                    // }
                    // if(flag)
                    // {
                    //     break;
                    // }
                    if(is_primes[j/i] && j/i!=i)
                    {
                        count++;
                    }
                }
            }
        // }
    }
    cout<<"Toal Count: "<<endl;
    cout<<count<<endl;
    return 0;
}