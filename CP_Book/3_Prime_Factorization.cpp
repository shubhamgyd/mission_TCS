// In this program we are finding the prime numbers of a number

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n=100;
    cout<<"Prime Factorization of a number: number , time of occurance: "<<endl;
    for(int i=2;i<=sqrt(n);i++)
    {
        int count=0;
        while(n%i==0)
        {
            n=n/i;
            count++;
        }
        cout<<"("<<i<<"^"<<count<<")"<<endl;
    }
    if(n!=1)
    {
        cout<<"("<<n<<"^"<<1<<")"<<endl;
    }


}