#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
#define endl '\n'
#define nline cout<<"\n"
#define max_pq priority_queue<int>
#define min_pq priority_queue<int, vector<int>, greater<int>>
#define For(i, x, n) for (i = x; i < n; ++i)
#define pb push_back
#define yes cout<<"YES"
#define no cout<<"NO"
#define int long long
// #define y cout<<"Yes"
#define nn cout<<"No"
#define ll long long

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 
int gcd(int a,int b) {
    if (b==0) return a;
    return gcd(b,a%b);
}
 
string to_upper(string &a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string &a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}


const int mod = 1e9 + 7;
const int INF = 1e9;

#define int long long
#define double long double
#define rep(i, a, b, c) for (int i = a; i < b; i += c)
#define bck(i, a, b, c) for (int i = a - 1; i >= b; i -= c)
#define f(i, n) rep(i, 0, n, 1)

/* ---------------------------------------------------------------------------------- */

struct node
{
    node *arr[26];
    int freq;
};

node *root = new node();
node *insert(string s)
{
    node *curr = root;
    for (int i = 0; i < s.length(); i++)
    {
        int t = s[i] - 'a';
        if (curr->arr[t] == NULL)
            curr->arr[t] = new node();
        curr->arr[t]->freq++;
        curr = curr->arr[t];
    }
    return root;
}
int search(string s)
{
    int cnt = 0;
    node *curr = root;
    for (int i = 0; i < s.length(); i++)
    {
        int t = s[i] - 'a';
        if (curr->arr[t] == NULL)
        {
            break;
        }
        cnt += curr->arr[t]->freq;
        curr = curr->arr[t];
    }
    return cnt;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s[n];
    f(i, n) cin >> s[i];
    f(i, n)
    {
        insert(s[i]);
    }
    f(i, n)
    {
        cout << search(s[i]) << endl;
    }
}
int32_t main()
{

    // int t; cin >> t;
    int t = 1;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}