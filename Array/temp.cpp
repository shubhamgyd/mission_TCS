#include <bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p)
{
	vector<int> v;
	unordered_map<char, int> ump;
	int varp = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		ump[p[i]]++;
	}
	int k = p.length();
	varp = ump.size();
	int b = 0;
	unordered_map<char, int> ums;
	int vars = 0;
	int i = 0, j = 0;
	while (j < s.length())
	{
		if (ump[s[j]] >= 1)
		{
			ums[s[j]]++;
			vars++;
			if (ums[s[j]] == ump[s[j]])
			{
				b++;
			}
		}
		if ((j - i + 1) < k)
			j++;
		else if ((j - i + 1) == k)
		{
			if (b == varp and vars == k)
			{
				v.push_back(i);
			}
			if (ump[s[i]] >= 1 and ums[s[i]] >= 1)
			{
				vars--;
				if (ums[s[i]] == ump[s[i]])
				{
					b--;
				}
				ums[s[i]]--;
			}
			i++;
			j++;
		}
	}
	return v;
}
int main()
{
	string s, t;
	cin >> s >> t;
	vector<int> ans = findAnagrams(s, t);
	for (auto it : ans)
	{
		cout << it << " ";
	}
	return 0;
}