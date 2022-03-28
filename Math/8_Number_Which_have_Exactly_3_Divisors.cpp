#include<bits/stdc++.h>
using namespace std;


bool isPrime(int n)
{
    for(int i=2;i<=n/2;i++)
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
    for(int i=2;i<100;i++)
    {
        int num=sqrt(i);
        // cout<<num<<endl;
        if(num*num==i && isPrime(num) && i>1)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}