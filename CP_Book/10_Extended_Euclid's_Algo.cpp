#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000009
#define fast()  ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
const int N=4E+5;

tuple<int,int,int> gcd(int a,int b)
{
    if(b==0)
    {
        return{1,0,a};
    }
    else
    {
        int x,y,g;
        tie(x,y,g)=gcd(b,a%b);
        return {y,x-(a/b)*y,g};
    }
}


int32_t main()
{
    int x,y,g;
    tie(x,y,g)=gcd(30,12);
    cout<<"X: "<<x<<", "<<"Y: "<<y<<" , "<<"G: "<<g<<endl;
}