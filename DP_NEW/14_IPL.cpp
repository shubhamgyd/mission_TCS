/*

Problem Name: IPL
Problem Difficulty: None
Problem Constraints: N < 1000000
a[i] < 1000
Problem Description:
In IPL 2025, the amount that each player is paid varies from match to match. The match fee depends on the quality of opposition, the venue etc.


The match fees for each match in the new season have been announced in advance. Each team has to enforce a mandatory rotation policy so that no player ever plays three matches in a row during the season.


Nikhil is the captain and chooses the team for each match. He wants to allocate a playing schedule for himself to maximize his 
earnings through match fees during the season.

Input Format: Line 1: A single integer N, the number of games in the IPL season.

Line 2: N non-negative integers, where the integer in position i represents the fee for match i.
Sample Input: 8
3 2 3 2 3 5 1 3
Output Format: The output consists of a single non-negative integer, the maximum amount of money that Nikhil can earn during this IPL 
season.
Sample Output: 17


*/
//=====Solution=====
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 1000005;
int a[N], dp[N];

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		dp[0] = a[0];
		dp[1] = a[1];
		dp[2] = a[2];
		for (i = 3; i <= n; i++) {
			dp[i] = a[i] + min({dp[i - 3], dp[i - 1], dp[i - 2]});
		}
		cout << sum - dp[n];
	}
}