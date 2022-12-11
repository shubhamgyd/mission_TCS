#include <iostream>
using namespace std;

int main()
{
    // Given availabe coins
    int coins[4] = {1, 4, 7, 9};
    // Required exchange
    int sum = 11;
    // Array size
    int n = 4;
    // Declare table
    int table[n + 1][sum + 1];
    // Initialize 0th column by 1 , if sum=0 then we can make sum=0 by 1 ways if we have n coins
    for (int i = 0; i <= n; i++)
    {
        table[i][0] = 1;
    }
    // Initialize 0th row by 0 , if number of coins=0 , we can't make any exchange anyore
    for (int i = 1; i <= sum; i++)
    {
        table[0][i] = 0;
    }

    // Now Iterate table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // If coins[i-1] is less than sum(j) then
            // we consider it
            if (coins[i - 1] <= j)
            {
                table[i][j] = table[i - 1][j] + table[i][j - coins[i - 1]];
            }
            // else just take the previous max exchange value
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    // Finally print the total maxWays to exchange given sum
    cout << table[n][sum] << endl;
    return 0;
}

/*
9 1 1
7 1 1 1 1
7 4
1 1 1 1 1 1 1 1 1 1 1
4 1 1 1 1 1 1 1
0 1 1 1 1 1 1 1 1 1 1 1
*/