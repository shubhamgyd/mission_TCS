#include <bits/stdc++.h>
using namespace std;
 
int coin_height(vector<vector<char>> &col, int c)
{
    int n = col.size();
    for (int i = 0; i < n; i++)
    {
        if (col[i][c] == 'C')
        {
            return n - 1 - i;
        }
    }
    return -1;
}
 
int coin_count(vector<vector<char>> &col, int c)
{
    int n = col.size(), count = 0;
    for (int i = 0; i < n; i++)
    {
        if (col[i][c] == 'C')
        {
            count++;
        }
    }
    return count;
}
 
int has_hurdle(vector<vector<char>> &col, int c)
{
    int n = col.size(), last = 0, flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (col[i][c] == 'H')
        {
            flag = 1;
        }
        if (col[i][c] != 'H')
        {
            last = i;
        }
    }
    if (!flag)
    {
        return -1;
    }
    return n - 1 - last;
}
 
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int I, J, C, M, N;
    cin >> I >> J >> C >> M >> N;
    vector<vector<char>> matrix(M, vector<char>(N, '0'));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int pos = 0;
    while (I && pos < N)
    {
        int coin = coin_height(matrix, pos);
        int hurdle = has_hurdle(matrix, pos);
        if (coin != -1)
        {
            int cc = coin_count(matrix, pos);
            I += C * cc;
            I -= J * coin;
        }
        else if (hurdle != -1)
        {
            I -= J * hurdle;
        }
        else
        {
            I -= 1;
        }
        if (I > 0)
        {
            pos++;
        }
    }
    cout << pos;
    return 0;
}