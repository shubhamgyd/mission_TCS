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
#define f first
#define s second
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

void solve()
{
	int n, x, y;
	cin >> n >> x >> y;
	// int half=n/2;
	// if((x>=half and y==0 ) or (y>=half and x==0))
	// {
	//     cout<<-1<<endl;
	//     return;
	// }
	if (y > x)
		swap(x, y);
	// cout<<"x: "<<x<<" y:"<<y<<endl;
	int res = (n - 1) % x;
	if (y != 0 or res or !x)
	{
		cout << -1 << endl;
		return;
	}
	vector<int> nums;
	int j = 1;
	for (int i = 0; i < n - 1; i++)
	{
		int parity = (i % 2);
		int num = i + j;
		if (parity == 0)
			nums.push_back(num);
		else
			nums.push_back(nums.back());
	}
	for (auto it : nums)
	{
		cout << it << " ";
	}
	cout << endl;
}

signed main()
{

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