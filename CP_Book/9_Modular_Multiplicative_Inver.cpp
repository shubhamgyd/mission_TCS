// In this problem we are going to see the modular multiplicative inverse of a given equation

#include<bits/stdc++.h>
using namespace std;

int extended_euclidean(int a,int m,int& x,int& y)
{
    if(m==0)
    {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=extended_euclidean(m,a%m,x1,y1);
    x=y1;
    y=x1-y1*(a/m);
    return d;
}

int main()
{
    int a,x,m,y;
    cin>>a>>m;
    int g=extended_euclidean(a,m,x,y);
    if(g!=1)
    {
        cout<<"Equation have no solution i.e. Modular Multiplicative Inverse"<<endl;
    }
    else
    {
        x=(x%m+m)%m;
        cout<<x<<endl;
    }
    return 0;

    
}