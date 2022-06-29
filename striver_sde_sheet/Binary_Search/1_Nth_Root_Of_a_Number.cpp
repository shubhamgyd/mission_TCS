/*
Problem Statement: Given two numbers N and M, find the Nth root of M.

The nth root of a number M is defined as a number X when raised to the power N equals M.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n, m;
    cin >> n >> m;

    // Brute Force
    bool ok = false;
    for (int i = 1; i <= sqrt(m); i++)
    {
        long long num = 1;
        for (int j = 0; j < n; j++)
        {
            num *= i;
        }
        if (num == m)
        {
            cout << i << endl;
            ok = true;
            break;
        }
    }
    // T:O(n*m)
    // S:O(1);

    // Using Binary Search
    //     Approach: In order to find the Nth root of any given integer we are gonna use Binary Search.
    // Step 1: Take low and high. Low will be equal to 1 and high will be M. We will take the mid of low and high such that the searching space is reduced using low + high / 2.
    // Step 2: Make a separate function to multiply mid N times.
    // Step 3: Run the while loop till (high – low > eps). Take eps as 1e-6, since we have to find answers to 6 decimal places.
    // Step 4:  If the mid is less than M, then we will reduce search space to low and mid. Else, if it is greater than M then search space will be reduced to mid and high.
    // Step 5: After the loop breaks we will have our answer as low or high.
    // We have to find the answer to 6 decimals. So, we will have a double 1e-6. We will run the while loop till (high – low > eps). When we will come out of the loop we will have the answer which will be equal to low as well as high.

    double low = 1.0;
    double high = m;
    double num = 0.0;
    double esp = 1e-6;
    while (low <= high)
    {
        double mid = (high + low) / (2.0);
        double number = 1.0;
        // cout<<"mid: "<<mid<<endl;
        for (int i = 1; i <= n; i++)
        {
            number *= mid;
        }
        if (number < m)
        {
            low = mid;
        }
        else if (number > m)
        {
            high = mid;
        }
        else
        {

            num = mid;
            break;
        }
    }
    cout << num << endl;
    // Time Complexity: N x log(M x 10^d)

    // Space Complexity: O(1)
}