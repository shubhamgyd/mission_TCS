#include <iostream>
using namespace std;

int main()
{
    // Iterate from i=2 to i=8
    for (int i = 2; i <= 8; i++)
    {
        // get factorial of current number
        int fact = 1;
        // multiply given number by i times
        for (int j = 1; j <= i; ++j)
        {
            fact = fact * j;
        }
        // Display number and factorial
        cout << i << "! = " << fact << endl;
    }
    return 0;
}