/*
Implement the function fib(n), 
which returns the nth number in the Fibonacci sequence, using only O(1) space.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a=0;
    int b=1;
    int c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    cout<<b<<endl;
    return 0;
}