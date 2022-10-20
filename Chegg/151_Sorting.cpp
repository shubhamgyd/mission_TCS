#include <iostream>
using namespace std;

// function with returns the squares the sum of numbers till n
long long int sqsum(int n)
{
    // get sum
    long long sum = 0;
    // Iterate from 1 to n
    for (int i = 1; i <= n; i++)
    {
        // add quares to get sum
        sum += (i * i);
    }
    // return sum
    return sum;
}

int main()
{
    // n= 5
    int n = 5;
    // get sum
    long long sum = sqsum(n);
    // print sum
    cout << sum << endl;
    return 0;
}
