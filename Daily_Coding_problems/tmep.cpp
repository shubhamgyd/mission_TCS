#include <bits/stdc++.h>
#define fast()                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define int long long
using namespace std;
#define endl '\n'
#define repFor(i, n) for (int i = 0; i < n; i++)
#define repiFor(i, x, n) for (int i = x; i < n; i++)

void DFS(int src, vector<int> adj[], vector<bool> &visited, int &end)
{
	end = src;
	if (visited[src])
		return;
	visited[src] = true;
	for (auto it : adj[src])
	{
		DFS(it, adj, visited, end);
	}
}

void Disp(int num)
{
	cout<<num<<endl;
}
void Input(vector<int>&res,int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>res[i];
	}
}


void D(int num,int num1)
{
	cout<<num<<" "<<num1<<" ";
}

void solve()
{
	int n;
	cin >> n;
	vector<int> res(n);
	Input(res,n);
	vector<int> evenArray, oddArray;
	for (int i = 0; i < n; i++)
	{
		if (res[i] & 1) oddArray.push_back(res[i]);
		else evenArray.push_back(res[i]);
	}
	if (n == 1 && oddArray.size() == 1)
	{
		// cout << oddArray[0] << endl;
		Disp(oddArray[0]);
		return;
	}
	if (oddArray.size() < 2)
	{
		// cout << -1 << endl;
		Disp(-1);
		return;
	}
	else if (oddArray.size() % 2)
	{
		if (evenArray.size() == 0)
		{
			// cout << -1 << endl;
			Disp(-1); return;
		}
		// cout << oddArray[0] << " " << oddArray[1] << " ";
		D(oddArray[0],oddArray[1]);
		for (int i = 0; i < evenArray.size(); i++) cout << evenArray[i] << " ";
		for (int i = 2; i < oddArray.size(); i++) cout << oddArray[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < oddArray.size(); i++) cout << oddArray[i] << " ";
		for (int i = 0; i < evenArray.size(); i++) cout << evenArray[i] << " ";
		cout << endl;
	}
}

signed main()
{
	// #ifndef ONLINE_JUDGE
	//     freopen("input.txt", "r", stdin);
	//     freopen("output.txt", "w", stdout);
	// #endif
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}