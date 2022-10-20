#include <bits/stdc++.h>
#define fast()                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;
#define endl '\n'
#define nline cout << "\n"
#define max_pq priority_queue<int>
#define min_pq priority_queue<int, vector<int>, greater<int>>
#define For(i, x, n) for (i = x; i < n; ++i)
#define pb push_back
#define yes cout << "YES"
#define no cout << "NO"
#define int long long
#define ff first
#define ss second
#define pb push_back
// #define mp make_pair
#define sz(v) (int)(v.size())
#define all(v) (v).begin(), (v).end()
// #define y cout<<"Yes"
// #define nn cout<<"No"
#define ll long long
#define limit1 30

int binpow(int a, int b)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int phi1(int n)
{
	int result = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}
tuple<int, int, int> extended_gcd(int a, int b)
{
	if (b == 0)
	{
		return {1, 0, a};
	}
	else
	{
		int x, y, g;
		tie(x, y, g) = extended_gcd(b, a % b);
		return {y, x - (a / b) * y, g};
	}
}

string to_upper(string &a)
{
	for (int i = 0; i < (int)a.size(); ++i)
		if (a[i] >= 'a' && a[i] <= 'z')
			a[i] -= 'a' - 'A';
	return a;
}

string to_lower(string &a)
{
	for (int i = 0; i < (int)a.size(); ++i)
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 'a' - 'A';
	return a;
}

const int mod = 1e9 + 7;
const int INF = 1e9;

void dfs(int src, int parent, vector<int> adj[], int mark[], int colors[], int parents[], int &cnt)
{
	if (colors[src] == 2)
		return;
	if (colors[src] == 1)
	{
		cnt++;
		int cur = parent;
		mark[cur] = cnt;
		while (cur != src)
		{
			cur = parents[cur];
			mark[cur] = cnt;
		}
		return;
	}
	parents[src] = parent;
	colors[src] = 1;
	for (auto it : adj[src])
	{
		if (it == parents[src])
			continue;
		dfs(it, src, adj, mark, colors, parents, cnt);
	}
	colors[src] = 2;
}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	k++;
	// cout << n << m << k << endl;
	vector<int> adj[10001];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// cout<<"Here"<<endl;
	int colors[10001];
	int parents[10001];
	int mark[10001];
	int cnt = 0;
	dfs(1, 0, adj, mark, colors, parents, cnt);
	vector<int> cycles[10001];
	for (int i = 1; i <= n; i++)
	{
		// cout<<"Here"<<endl;
		if (mark[i] != 0)
		{
			cycles[mark[i]].push_back(i);
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		// cout << cycles[i].size() << endl;
		// if (cycles[i].size() >= k)
		// {
		cout << cycles[i].size() << endl;
		for (auto it : cycles[i])
		{
			cout << it << " ";
			// }
			// return;
		}
		cout << endl;
	}
}

signed main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("inputf.in", "r", stdin);
	// 	freopen("outputf.out", "w", stdout);
	// #endif
	fast();
	// int t;
	// cin >> t;
	// while (t--)
	// {
	//     solve();
	// }
	solve();

	return 0;
}