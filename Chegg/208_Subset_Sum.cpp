#include <iostream>
using namespace std;

int main()
{
    // Input n and sum
    int n, x;
    cin >> n >> x;
    int arr[n];
    // Input of array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Declaration of array
    int table[n + 1][x + 1];
    // Fill first column true, because we can make zero sum
    for (int i = 0; i <= n; i++)
    {
        table[i][0] = true;
    }
    // Fill frst row false, because we can't make sum if have no elements
    for (int i = 1; i <= x; i++)
    {
        table[0][i] = false;
    }
    // Iterate Loops
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            // If element if less than or equal to given sum , then we have two choices
            // Either taken or not taken
            if (arr[i - 1] <= j)
            {
                table[i][j] = table[i - 1][j - arr[i - 1]] || table[i - 1][j];
            }
            // If element is greater than given sum ,  then take the value from the previos
            // upper array block
            // Discard it , store the previous valid flag
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    // If we make sum then print 1
    if (table[n][x] == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    // Else print 0
    cout << 0 << endl;
    return 0;
}