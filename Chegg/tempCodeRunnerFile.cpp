#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	unordered_set<int> st;
	for (auto it : nums)
	{
		st.insert(it);
	}
	int size = st.size();
	int ans = ((size % MOD) * (size % MOD));
	cout << ans << endl;
	return 0;
}