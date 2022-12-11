#include <iostream>
using namespace std;

int main()
{
    // Input of three numbers
    int a, b, c;
    cin >> a >> b >> c;
    // If a is greater than or equal to b and c
    // Print a
    if (a >= b and a >= c)
    {
        cout << a << endl;
    }
    // If b is greater than or equal to a and c
    // Print b
    else if (b >= a and b >= c)
    {
        cout << b << endl;
    }
    // If c is greater than or equal to b and a
    // Print c
    else if (c >= a and c >= b)
    {
        cout << c << endl;
    }
    return 0;
}