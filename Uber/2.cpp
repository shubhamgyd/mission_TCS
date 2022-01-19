/*
Rotate the matrix k times
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    int k;
    cin >> k;
    k %= 4;
    while (k--)
    {
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = i; j < n - i - 1; j++)
            {
                if (i != j && (i + j) != (n - 1))
                {
                    int N = mat.size();

                    // Stores the last row
                    int ei = N - 1 - i;

                    // Stores the last column
                    int ej = N - 1 - j;

                    // Perform the swaps
                    int temp = mat[i][j];
                    mat[i][j] = mat[ej][i];
                    mat[ej][i] = mat[ei][ej];
                    mat[ei][ej] = mat[j][ei];
                    mat[j][ei] = temp;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}