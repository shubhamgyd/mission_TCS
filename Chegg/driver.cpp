#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int process;
	cin >> process;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		pq.push(arr[i]);
	}
	int cnt = 0;
	unordered_map<int, int> mp;
	while (process > 0)
	{
		// cout << "here" << endl;
		int cap = pq.top();
		pq.pop();
		process -= cap / 2;
		pq.push(cap / 2);
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}