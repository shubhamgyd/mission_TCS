#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define lli long long int
//#define str string
#define MOD 10000007

lli binpow(lli a,lli b)
{
    lli res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=res*a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}

void solve()
{
    lli a,b;
    cin>>a>>b;
    a%=MOD;
    lli res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=res*a%MOD;
        }
        a=a*a%MOD;
        b>>=1;
    }
    cout<<res<<endl;
}

lli gcd(lli a, lli b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}


int ExtendedGCD(int a,int b,int& x,int& y)
{
    x=1,y=0;
    int x1=0,y1=1,a1=a,b1=b;
    while(b1)
    {
        int q=a1/b1;
        tie(x,x1)=make_tuple(x1,x-q*x1);
        tie(y,y1)=make_tuple(y1,y-q*y1);
        tie(a1,b1)=make_tuple(b1,a1-q*b1);
    }
    return a1;
}

int gcd1(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd1(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int gcd2(int a, int b) {
    if(b==0)
    {
        return a;
    }
    return gcd2(b,a%b);
}

bool find_solution(int a,int b,int c,int&x0,int&y0,int& g)
{
    g=gcd1(abs(a),abs(b),x0,y0);
    if(c%g)
    {
        return false;
    }
    x0*=c/g;
    y0*=c/g;
    if(a<0) x0=-x0;
    if(b<0) y0=-y0;
    return true;
}

void findCombination(vector<int>&v , string output,int n,int k)
{
	if(k>n)
	{
		return;
	}
	if(k==0)
	{
        sort(output.begin(),output.end());
		cout<<output<<endl;
        return;
	}
	for(int i=n-1;i>=0;i--)
	{
		findCombination(v,to_string(v[i])+" "+output,i,k-1);
	}
}

int main()
{
    fast();
    int n,k;
    cin>>n;
    vector<int>v;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
    cin>>k;
	findCombination(v,"",n,k);
    return 0;
}


