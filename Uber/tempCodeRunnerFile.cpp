#include <bits/stdc++.h>
using namespace std;

struct Result
{
	Result() : output1(){};
	int output1[100];
};

Result SortStudentMarks(int input1, int input2, int **input3)
{
	Result res;
	int mn = INT_MAX;
	int ind = 0;
	for (int i = 0; i < input2; i++)
	{
		int temp = 0;
		for (int j = 0; j < input1; j++)
		{
			temp += input3[j][i];
		}
		int result = temp / input1;
		if (result < mn)
		{
			mn = result;
			ind = i;
		}
	}
	int cnt = 0;
	for (int i = 0; i < input1; i++)
	{
		int sum = 0;
		for (int j = 0; j < input2; j++)
		{
			if (j != ind)
			{
				sum += input3[i][j];
			}
		}
		res.output1[cnt] = sum;
		cnt++;
	}
	sort(res.output1, res.output1 + input1, greater<int>());
	return res;
}

int CollectMoney(int input1, int **input2)
{
	int m = input1;
	int n = input1;
	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = input2[0][0];
	for (int i = 1; i < m; i++)
		dp[i][0] = dp[i - 1][0] + input2[i][0];
	for (int j = 1; j < n; j++)
		dp[0][j] = dp[0][j - 1] + input2[0][j];
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + input2[i][j];
	return dp[m - 1][n - 1];
}

// do
// {
// 	int v;
// 	char sep;
// 	auto code = scanf("%d%c", &v, &sep);
// 	if (code >= 1)
// 	{
// 		adj[i].push_back(v);
// 	}
// 	if (code < 2 || sep == '\n')
// 	{
// 		break;
// 	}
// } while (true);

#include <bits/stdc++.h>
using namespace std;

int main()
{
	printf("%d\t", sizeof(90000));
	printf("%d\t", sizeof(18.5));
	printf("%d", sizeof('C'));
	return 0;
}