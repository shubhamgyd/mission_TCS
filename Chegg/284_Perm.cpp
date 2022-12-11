#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Given array
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    // get totalCount
    int cnt = 0;
    // Try every possible permutation
    do
    {
        // Iterate permutated array
        for (int i = 0; i < 6; i++)
        {
            for (int j = i + 1; j < 6; j++)
            {
                // Check given condition satisfied or not
                // if yes then increment the count
                if ((arr[i] == 1 and arr[j] == 2) or (arr[i] == 2 and arr[j] == 3) or (arr[i] == 5 and arr[j] == 6))
                {
                    cnt++;
                    break;
                }
            }
        }
    } while (next_permutation(arr.begin(), arr.end()));
    // Display totalCount
    cout << cnt << endl;
}