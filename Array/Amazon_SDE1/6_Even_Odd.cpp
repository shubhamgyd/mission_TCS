#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
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