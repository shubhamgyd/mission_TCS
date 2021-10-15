#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> all_possible(vector<int> A)
{
	int N = A.size();
	map<int, int> mp;
	for (auto it : A)
	{
		mp[it]++;
	}
	A.clear();
	for(auto it:mp)
	{
		A.push_back(it.first);
	}
	set<int> st;
	if (mp.size() == 1)
	{
		auto it = mp.begin();
		return {it->second};
	}
	else
	{
		sort(A.begin(), A.end());
		do
		{
			// map<int,int>temp(mp.begin(),mp.end());
			int val = 0;
			for (int i = 0; i < N; i++)
			{
				// cout<<A[i]<<" ";
				auto it = mp.begin();
				auto ele = mp.end();
				// cout<<it->second<<" "<<ele->second<<endl;
				ele--;
				if (it->first == A[i])
				{
					val -= it->second;
				}
				else if (ele->first ==A[i])
				{
					val += ele->second;
				}
			}
			st.insert(val);
		} while (next_permutation(A.begin(), A.end()));
	}
	vector<int> ans;
	for (auto it : st)
	{
		// cout<<it<<" ";
		ans.push_back(it);
	}
	return ans;
}
int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> res;
		// map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			res.push_back(a);
			// mp[a]++;
		}
		vector<int> fin = all_possible(res);
		for(auto it:fin)
		{
			cout<<it<<" ";
		}
	}
}