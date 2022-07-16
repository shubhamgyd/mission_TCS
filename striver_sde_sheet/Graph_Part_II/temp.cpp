#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int j=n;
    int i=1;
    while(i<=j)
    {
        cout<<(j^i)<<" ";
        i++;
        j--;
    }
    cout<<endl;
    i=1;
    j=n;
    while(i<=j)
    {
        cout<<i<<" "<<j<<" ";
        i++;
        j--;
    }
}