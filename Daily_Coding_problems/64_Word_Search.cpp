/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<char>> &res, int k, int i, int j, int n, int m, string word)
{
    if (i < 0 || i >= n || j < 0 || j >= m || res[i][j] != word[k])
    {
        return false;
    }
    if (k == word.length() - 1)
    {
        return true;
    }
    char ch = res[i][j];
    res[i][j] = '*';
    bool search = solve(res, k + 1, i + 1, j, n, m, word) || 
                  solve(res, k + 1, i - 1, j, n, m, word) || 
                  solve(res, k + 1, i, j + 1, n, m, word) || 
                  solve(res, k + 1, i, j - 1, n, m, word);
    res[i][j]=ch;
    return search;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> res(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> res[i][j];
        }
    }
    string word;
    cin >> word;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            bool temp=solve(res, 0, 0, 0, n, m, word);
            if(temp)
            {
                cout<<"Found"<<endl;
                return 0;
            }
        }
    }
    cout<<"Not Found"<<endl;
    return 0;
}