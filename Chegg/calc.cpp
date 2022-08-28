#include<bits/stdc++.h>
using namespace std;

int temp;
void solve(int n)
{
    if(n==0) return;
    if(n>temp) return;
    if(n<=temp)
    {
        solve(n-1);
        cout<<n<<endl;
    }
    else
    {
        solve(n+1);
        cout<<n<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    temp=n;
    solve(n);
    return 0;
}   