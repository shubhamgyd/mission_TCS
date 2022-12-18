// C++ program to maximize the Bitwise
// OR Sum in given array
#include <bits/stdc++.h>
using namespace std;

// Function to maximize the bitwise
// OR sum
int maxOR(long long arr[], int n, int k, int x)
{
    long long preSum[n + 1], suffSum[n + 1];
    long long res, pow = 1;

    // Compute x^k
    for (int i = 0; i < k; i++)
        pow *= x;

    // Find prefix bitwise OR
    preSum[0] = 0;
    for (int i = 0; i < n; i++)
        preSum[i + 1] = preSum[i] | arr[i];

    // Find suffix bitwise OR
    suffSum[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        suffSum[i] = suffSum[i + 1] | arr[i];

    // Find maximum OR value
    res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, preSum[i] | (arr[i] * pow) | suffSum[i + 1]);

    return res;
}

// Drivers code
int main()
{
    long long arr[] = {1, 2, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2, x = 2;

    cout << maxOR(arr, n, k, x) << "\n";

    return 0;
}
