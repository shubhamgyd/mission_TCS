#include <iostream>
using namespace std;

int main()
{
    // Matrix of size 5x4
    int arr[5][4];
    // Get random number at each cell in a matrix
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // generate random number between 10 to 99
            int randomNum = 10 + (std::rand() % (99 - 10 + 1));
            arr[i][j] = randomNum;
        }
    }
    // Display matrix
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // Get maximum gap in each row
    for (int i = 0; i < 5; i++)
    {
        int mxGap = 0;
        for (int j = 0; j < 3; j++)
        {
            // get maximum gap between adjacent elements
            mxGap = max(mxGap, arr[i][j + 1] - arr[i][j]);
        }
        // Print maximum gap
        cout << "Max gap in row " << i << ": " << mxGap << endl;
    }
    // Get number divisible by 3 or 5 in each row
    int divisible[5];
    for (int i = 0; i < 5; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 4; j++)
        {
            // if number is divisble by 3 or 5 then count it
            if (arr[i][j] % 3 == 0 or arr[i][j] % 5 == 0)
            {
                cnt++;
            }
        }
        // put it into the row i
        divisible[i] = cnt;
    }
    // Display divisible numbers in each row by 3 or 5
    cout << "# elements divisible by 3 or 5 in each row: ";
    for (int i = 0; i < 5; i++)
    {
        cout << divisible[i] << " ";
    }
    return 0;
}