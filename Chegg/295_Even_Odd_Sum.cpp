#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Given array
    int arr[] = {3, 2, 4, 7, 3, 4, 5};
    // Get size of aaray
    int n = sizeof(arr) / sizeof(arr[0]);
    // Store evenSum
    int evenSumCount[n + 1];
    // Store oddSum
    int oddSumCount[n + 1];

    // Initialising countEVEN[0] and countODD[0] to 0
    // since as there is no subsequence before the
    // iteration with even or odd count.
    evenSumCount[0] = 0;
    oddSumCount[0] = 0;

    // Iterate array
    for (int i = 1; i <= n; i++)
    {

        // if the number is even
        if (arr[i - 1] % 2 == 0)
        {
            evenSumCount[i] = evenSumCount[i - 1] + evenSumCount[i - 1] + 1;
            oddSumCount[i] = oddSumCount[i - 1] + oddSumCount[i - 1];
        }
        // if the number is odd
        else
        {
            evenSumCount[i] = evenSumCount[i - 1] + oddSumCount[i - 1];
            oddSumCount[i] = oddSumCount[i - 1] + evenSumCount[i - 1] + 1;
        }
    }
    // Print evenSumCount and oddSumCount
    cout << evenSumCount[n] << " " << oddSumCount[n] << endl;
    return 0;
}