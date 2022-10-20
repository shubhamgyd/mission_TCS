#include <iostream>
using namespace std;

int main()
{
    // Read total Transactions
    int n;
    cin >> n;
    // Array to store transactions
    int transactions[n];
    // Get transcations on each day
    for (int i = 0; i < n; ++i)
    {
        cin >> transactions[i];
    }
    // Declare and Initialize totalGainCount with 0
    int totalGainCount = 0;
    // Iterate from start
    for (int i = 0; i < n; ++i)
    {
        // Check on it's next days
        for (int j = i + 1; j < n; ++j)
        {
            // if transactions on day j is greater than transactions on day i
            // then gain
            // increment count
            if (transactions[j] > transactions[i])
            {
                totalGainCount++;
            }
        }
    }
    // Display totalGainCount
    cout << totalGainCount << endl;
    return 0;
}