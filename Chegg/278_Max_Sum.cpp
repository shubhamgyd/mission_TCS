#include <iostream>
using namespace std;

int main()
{
    // Read size of array
    int n;
    cin >> n;
    int nums[n];
    // Ready array elements
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // Declare table array of size nx2
    int table[n][2];
    // Base case
    // if size of array is 1
    if (n == 1)
    {
        cout << nums[0] << endl;
        return 0;
    }
    // Initialize the values in table array
    table[0][0] = 0;
    table[0][1] = nums[0];
    // Iterate in the array and find the maximum sum
    for (int i = 1; i < n; i++)
    {
        // At index i we have two choices
        // eihter take the previous maximum value + nums[i] ( not adjacent)
        // or take the previous maximum value and store it
        table[i][1] = table[i - 1][0] + nums[i];
        table[i][0] = max(table[i - 1][1], table[i - 1][0]);
    }

    // get the maximum sum
    int maxSum = max(table[n - 1][0], table[n - 1][1]);
    // Display max value
    cout << maxSum << endl;
    return 0;
}