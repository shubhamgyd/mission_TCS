#include <bits/stdc++.h>
using namespace std;



int fun(int p,int q,int r)
{
    if((q%p)<r || (p&r)<r)
    {
        q=(p+q)^r;
        r=(q&3)+p;
    }
    else
    {
        q=(p+12)+q;
        q=(p^r)+q;
    }
    return p+q+r;
}
int main()
{
    // // int p=0,q=7,r=5;
    // // p=(q+6)^q;
    // // if((r-q),(q-r))
    // // {
    // //     r=(p+r)+p;
    // //     r=r+r;
    // // }
    // cout<<p+q+r<<endl;
    cout<<fun(1,7,4)<<endl;
    
}