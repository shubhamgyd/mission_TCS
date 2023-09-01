#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	int n;
	cin >> n;
	vector<int> boss(n), foot(n);
	for (int i = 0; i < n; i++)
	{
		cin >> boss[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> foot[i];
	}
	multiset<int> st;
	int prev = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			st.insert(foot[i]);
		}
		else
		{
			auto it = st.lower_bound(boss[i]);
			if (it != st.begin())
			{
				it--;
				prev = (*it);
				cout << prev << endl;
			}
			st.insert(foot[i]);
		}
		for (auto it : st)
		{
			cout << it << " ";
		}
		cout << endl;
	}
	int sz = st.size();
	cout << sz - prev << endl;
	return 0;
}