#include<bits/stdc++.h>
using namespace std;


void pat(int n)
{
    for(int i=1;i<=n;i++)
    {
        int j=2*i;
        while(j--)
        {
            cout<<1;
        }
        cout<<endl;
    }
}

int main()
{
    int num;
    cin>>num;
    pat(num);
    if(num%2==0)
    {
        int i=0;
        int ct=0;
        while(ct!=num)
        {
            cout<<i<<" ";
            ct++;
            i+=2;
        }
    }
    else
    {
        int ct=0;
        int i=1;
        while(ct!=num)
        {
            cout<<i<<" ";
            i+=2;
            ct++;
        }
    }
}