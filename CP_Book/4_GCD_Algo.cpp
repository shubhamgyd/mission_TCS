// In this program we are finding greatest common divisor of two numbers
#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int euclids_Algo(int a,int b)
{
    int dividend=a;
    int divisor=b;
    while(divisor!=0)
    {
        int rem=dividend%divisor;
        dividend=divisor;
        divisor=rem;
    }
    return dividend;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n=999,m=345;
    cout<<"Common Divisor of both numbers is: "<<euclids_Algo(n,m)<<endl;
    return 0;


}