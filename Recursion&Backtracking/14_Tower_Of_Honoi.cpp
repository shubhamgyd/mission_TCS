#include<bits/stdc++.h>
using namespace std;

void solve(int n,int from,int to,int aux)
{
    if(n==1)
    {
        cout<<"Moving plate "<<n<<" from "<<from<<" to "<<to<<endl;
        return;
    }
    solve(n-1,from,aux,to);
    cout<<"Moving plate "<<n<<" from "<<from<<" to "<<to<<endl;
    solve(n-1,aux,to,from);
    return;
}

int main()
{
    int n;
    cin>>n;
    solve(n,1,3,2);
    return 0;
}