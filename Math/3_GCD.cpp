#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
// Time Complexity:O(log(b))


tuple<int,int,int> extended_gcd(int a,int b)
{
    if(b==0)
    {
        // here a is gcd
        return {1,0,a};
    }
    else
    {
        int x,y,g;
        tie(x,y,g)=extended_gcd(b,a%b);
        return {y,x-y*(a/b),g};
    }
}
// Time Complexity:O(log(b))


int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"GCD of a and b is: "<<gcd(a,b)<<endl;

    int x,y,g;
    tie(x,y,g)=extended_gcd(a,b);
    cout<<"x: "<<x<<" ,y: "<<y<<", g: "<<g<<endl;
    return 0;
}