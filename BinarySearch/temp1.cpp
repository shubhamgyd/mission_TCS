#include <bits/stdc++.h>
using namespace std;

void solution(int x1, int y1, int x2, int y2, int n, int m, int &cnt, char ch, vector<vector<int>> &dp)
{
	if (x1 < 0 and y1 < 0)
	{
		cnt++;
		dp[x1 + 1][y1]++;
		solution(x1 + 1, y1 + 1, x2, y2, n, m, cnt, 'R', dp);
	}
	if (x1 >= n and y1 >= m)
	{
		cnt++;
		dp[x1 - 1][y1 - 1]++;
		solution(x1 - 1, y1 - 1, x2, y2, n, m, cnt, 'L', dp);
	}
	if (y1 < 0 and x1 >= 0)
	{
		cnt++;
		dp[x1][y1 + 1]++;
		solution(x1, y1 + 1, x2, y2, n, m, cnt, 'D', dp);
	}
	if (x1 < 0 and y1 >= 0)
	{
		cnt++;
		dp[x1 + 1][y1]++;
		solution(x1 + 1, y1, x2, y2, n, m, cnt, 'U', dp);
	}
	if (x1 == x2 and y1 == y2)
	{
		return;
	}
	if (dp[x1][y1] >= 2)
	{
		cnt = -1;
		return;
	}
	if (ch == 'R')
	{
		cnt++;
		dp[x1 + 1][y1 + 1]++;
		solution(x1 + 1, y1 + 1, x2, y2, n, m, cnt, ch, dp);
	}
	if (ch == 'L')
	{
		cnt++;
		dp[x1 - 1][y1 - 1]++;
		solution(x1 - 1, y1 - 1, x2, y2, n, m, cnt, ch, dp);
	}
	if (ch == 'D')
	{
		cnt++;
		dp[x1 - 1][y1 + 1]++;
		solution(x1 - 1, y1 + 1, x2, y2, n, m, cnt, ch, dp);
	}
	else
	{
		cnt++;
		dp[x1 + 1][y1 - 1]++;
		solution(x1 + 1, y1 - 1, x2, y2, n, m, cnt, ch, dp);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int cnt = 0;
	char dir = 'R';
	vector<vector<int>> dp(n, vector<int>(m, 0));
	solution(x1, y1, x2, y2, n, m, cnt, dir, dp);
	cout << cnt << endl;
	return 0;
}