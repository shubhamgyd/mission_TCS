// #include<bits/stdc++.h>
// using namespace std;

// int distinctIds(vector<int>arr, int n, int m)
// {
//     unordered_map<int, int> mp;
//     vector<pair<int, int> > res;
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
// 		mp[arr[i]]++;
// 	}
//     for (auto it = mp.begin(); it != mp.end(); it++)
//     {
// 		res.push_back(make_pair(it->second, it->first));
// 	}
//     sort(res.begin(), res.end());

//     int size = res.size();
//     for (int i = 0; i < size; i++)
// 	 {
//         if (res[i].first <= m)
// 		{
//             m -= res[i].first;
//             cnt++;
//         }
//         else
//         {
// 			return size - cnt;
// 		}
//     }
//     return size - cnt;
// }

// int distinctSubstring(string& P, int N)
// {

//     unordered_set<string> S;
//     for (int i = 0; i < N; ++i)
// 	{
//         vector<bool> freq(26, false);
//         string s;

//         for (int j = i; j < N; ++j)
// 		{
//             int pos = P[j] - 'a';
//             if (freq[pos] == true)
//             {
// 				break;
// 			}

//             freq[pos] = true;
//             s += P[j];
//             S.insert(s);
//         }
//     }
//     return S.size();
// }
// int main()
// {
// 	int n;
// 	cin>>n;
// 	vector<int>nums(n);
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>nums[i];
// 	}
// 	int m;
// 	cin>>m;
// 	cout<<distinctIds(nums,n,m)<<endl;
// }

// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to count total
// number of valid substrings
long long int countSub(string str)
{
	int n = (int)str.size();
	long long int ans = 0;
	int cnt[26];

	memset(cnt, 0, sizeof(cnt));
	int i = 0, j = 0;

	while (i < n)
	{
		if (j < n && (cnt[str[j] - 'a'] == 0))
		{

			cnt[str[j] - 'a']++;
			ans += (j - i + 1);
			j++;
		}
		else
		{
			cnt[str[i] - 'a']--;
			i++;
		}
	}
	return ans;
}

int distinctIds(vector<int>nums, int n, int m)
{
    unordered_map<int, int> mp;
    vector<pair<int, int> > res;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
		mp[nums[i]]++;
	}
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
		res.push_back(make_pair(it->second, it->first));
	}
    sort(res.begin(), res.end());
 
    int size = res.size();
    for (int i = 0; i < size; i++)
	 {
        if (res[i].first <= m) 
		{
            m -= res[i].first;
            cnt++;
        }
        else
        {
			return size - cnt;
		}
    }
    return size - cnt;
}

// Driver Code
int main()
{
	string str = "bcada";

	cout << countSub(str);

	return 0;
}
