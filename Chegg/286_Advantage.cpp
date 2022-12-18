#include <iostream>
using namespace std;

int main()
{
    // Read array size n
    int n;
    cin >> n;
    // Array A and B of size n
    int A[n], B[n];
    // Read array A elements
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    // Read array B elements
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    // Get total advantage of array A over B
    int advantage = 0;
    // Iterate from 0 to n
    for (int i = 0; i < n; i++)
    {
        // If A[i] > B[i]
        // then increment the count
        if (A[i] > B[i])
        {
            advantage++;
        }
    }
    // Display total advantage
    cout << advantage << endl;
    return 0;
}