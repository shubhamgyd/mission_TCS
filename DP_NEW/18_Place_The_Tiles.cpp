/*
Problem Name: Place the tiles
Problem Difficulty: 
Problem Constraints: 1<= N < 100000000
Problem Description:
Given a <b>“2 x n”</b> board and tiles of size <b>“2 x 1”</b>, print the number of ways to tile the given board using the 2 x 1 tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.

Input Format: The only line of the input contains <b>N</b> to represent the second dimension of the board.
Sample Input: 3
Output Format: Print the number of ways to tile the given board .
<p>
<b>Note: Since the answer can be huge, print ans % 1000000007. </b>
</p>
Sample Output: 3



=====Solution=====
*/


#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 #define fio ios_base::sync_with_stdio(false)
 
#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
 
#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
 
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}


int PlaceTiles(int n)
{
    int dp[10001];
    
    // at 1 tiles we can placed only in one way
    dp[1]=1;

    // for 2 tiles we can put either horizantal or vertical
    dp[2]=2;

    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main()
{
  // freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll n;
    cin>>n;
    ll a=1;
    ll b=2;
    // Note that if we place the tile vertically the problem reduces to finding the number of ways in 2 X n-1 board
    // If we place the tile horizontally , the problem reduces to finding the number of ways in 2 x n-2  board since 
    // only 1 tile can only be placed in only horizontal manner above the horizontally placed tile.
    // So total number of ways : F(n)= F(n+1)+F(n+2).
    // Or if placed in the opposite manner : F(n) = F(n-1) + F(n-2) = nth fibonacci number

    if(n==1)cout<<a<<endl;  // base case 1.
    else if(n==2)cout<<b<<endl; // base case 2.
    else{
      ll c;
      for(ll i=3;i<=n;i++){
        c=a+b;
        c%=mod;
        a=b;
        b=c;
      }
      cout<<c<<endl;
    }
  }
}
