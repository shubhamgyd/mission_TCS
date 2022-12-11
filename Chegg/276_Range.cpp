#include <iostream>
using namespace std;

int main()
{
    // Read value of x
    cout << "Enter value of x: ";
    int x;
    cin >> x;
    // initial value of series is 2
    int a = 2;
    // Display series
    cout << "First x terms of the series are : ";
    // Iterate from 1 to x
    // and every time display a
    for (int i = 1; i <= x; i++)
    {
        if (i < x)
        {
            cout << a << " + ";
        }
        else
        {
            cout << a << endl;
        }
        // Update value of by a=a+i for next iteration
        a += i;
    }
}