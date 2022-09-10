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
#define mp make_pair
#define sz(v) (int)(v.size())
#define all(v) (v).begin(), (v).end()
// #define y cout<<"Yes"
// #define nn cout<<"No"
#define ll long long

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

int cnt = 0;
void dfs(int src, vector<int> adj[], int visited[])
{
	visited[src] = cnt;
	if (adj[src].size() > 0)
	{
		for (auto it : adj[src])
		{
			if (visited[it] == 0)
				dfs(it, adj, visited);
		}
	}
	return;
}

void solve()
{
	int n, k, r, c;
	cin >> n >> k >> r >> c;
	r--;
	c--;
	// k--;
	vector<vector<char>> res(n, vector<char>(n, '.'));
	res[r][c] = 'X';
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	visited[r][c] = true;
	int i = r - 1;
	int j = c + 1;
	while (i >= 0 and j < n)
	{
		res[i][j] = 'X';
		visited[i][j] = true;
		i--;
		j++;
	}
	i = r + 1;
	j = c - 1;
	while (i < n and j >= 0)
	{
		// cout<<"H"<<endl;
		res[i][j] = 'X';
		visited[i][j] = true;
		i++;
		j--;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (visited[i][j])
			{
				if (i - k >= 0)
				{
					visited[i - k][j] = true;
					res[i][j] = 'X';
					for (int l = j + 1; l < min(n, j + k); l++)
					{
						visited[i][l] = true;
					}
					for (int l = j - 1; l > max(0LL, abs(j - k)); l--)
					{
						visited[i][l] = true;
					}
					for (int l = i - 1; l > max(0LL, abs(i - k)); l--)
					{
						visited[l][j] = true;
					}
					for (int l = i + 1; l < min(n, i + k); l++)
					{
						visited[l][j] = true;
					}
				}
				if (i + k < n)
				{
					visited[i + k][j] = true;
					res[i][j] = 'X';
					for (int l = j + 1; l < min(n, j + k); l++)
					{
						visited[i][l] = true;
					}
					for (int l = j - 1; l > max(0LL, abs(j - k)); l--)
					{
						visited[i][l] = true;
					}
					for (int l = i - 1; l > max(0LL, abs(i - k)); l--)
					{
						visited[l][j] = true;
					}
					for (int l = i + 1; l < min(n, i + k); l++)
					{
						visited[l][j] = true;
					}
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				// cout<<"here"<<endl;
				bool up = true;
				bool down = true;
				bool right = true;
				bool left = true;
				if (abs(i - k >= 0) and res[abs(i - k)][j] != 'X' and !visited[abs(i - k)][j])
					up = false;
				if (i - k < 0)
					up = false;
				if (i + k < n and res[i + k][j] != 'X' and !visited[i + k][j])
					down = false;
				if (i + k >= n)
					down = false;
				if (abs(j - k) >= 0 and res[i][abs(j - k)] != 'X' and !visited[i][abs(j - k)])
					left = false;
				if (j - k < 0)
					left = false;
				if (j + k < n and res[i][j + k] != 'X' and !visited[i][k + j])
					right = false;
				if (j + k >= n)
					right = false;
				// cout<<up<<" "<<down<<" "<<right<<" "<<left<<endl;
				if (!up and !down and !right and !left)
				{
					res[i][j] = 'X';
				}
				for (int l = j + 1; l < min(n, j + k); l++)
				{
					visited[i][l] = true;
				}
				for (int l = j - 1; l > max(0LL, abs(j - k)); l--)
				{
					visited[i][l] = true;
				}
				for (int l = i - 1; l > max(0LL, abs(i - k)); l--)
				{
					visited[l][j] = true;
				}
				for (int l = i + 1; l < min(n, i + k); l++)
				{
					visited[l][j] = true;
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << res[i][j];
		}
		cout << endl;
	}
	// vector<vector<char>>grid(n+1,vector<char>(n+1,'.'));
	// for(int l=2;l<=n*2;++l)
	// {
	//     if(abs(r+c-l)%k==0)
	//     {
	//         for(int i=1;i<=n;++i)
	//         {
	//             for(int j=1;j<=n;++j)
	//             {
	//                 if(i+j==l)
	//                 {
	//                     grid[i][j]='X';
	//                 }
	//             }
	//         }
	//     }
	// }
	// for(int i=1;i<=n;++i)
	// {
	//     for(int j=1;j<=n;++j)
	//     {
	//         cout << grid[i][j];
	//     }
	//     cout<<endl;
	// }
}

signed main()
{
	// #ifndef ONLINE_JUDGE
	//         freopen("inputf.in", "r", stdin);
	//         freopen("outputf.out", "w", stdout);
	// #endif
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	// solve();

	return 0;
}