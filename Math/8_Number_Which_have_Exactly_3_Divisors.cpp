#include<bits/stdc++.h>
using namespace std;


int is_primes[100];
set<int>my_bucket;
void Primes()
{
    memset(is_primes,0,sizeof(is_primes));
    is_primes[0]=is_primes[1]=1;
    for(int i=2;i<=100;i++)
    {
        if(is_primes[i])
        {
            for(int j=i*i;j<=100;j+=i)
            {
                is_primes[j]=1;
            }
        }
    }
    for(int i=2;i<=100;i++)
    {
        if(is_primes[i]==0)
        {
            my_bucket.insert(i*i);
        }
    }

    // for(auto it:my_bucket)
    // {
    //     cout<<it<<" ";
    // }
}


void is_divisor_three(int n)
{
    if(my_bucket.find(n)!=my_bucket.end())
    {
        cout<<"Given element has three divisors..."<<endl;
    }
    else
    {
        // cout<<"Given Element has not three divisors"<<endl;
    }
    

}


bool isPrime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Primes();
    for(int i=2;i<100;i++)
    {
        is_divisor_three(i);
        int num=sqrt(i);
        // cout<<num<<endl;
        if(num*num==i && isPrime(num) && i>1)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
// Time Complexity :O(root n)