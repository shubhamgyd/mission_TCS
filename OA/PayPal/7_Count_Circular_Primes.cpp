/*
The number, 197, is called a circular prime because all rotations (not all permutations) of the
 digits, 197.971, and 719, are themselves prime

There are thirteen such primes below 100: 2, 3, 5.7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

Write a program to count the number of circular prime numbers less than or equal to a given

number.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find total number of digits
int countDigits(int n)
{
    int digit = 0;
    while (n /= 10)
        digit++;
    return digit;
}

// Rotate function to right rotate the number
int Rotate(int n)
{
    int rem = n % 10;               // find unit place number
    rem *= pow(10, countDigits(n)); // to put unit place
    // number as first digit.
    n /= 10;  // remove unit digit
    n += rem; // add first digit to rest
    return n;
}

void SieveOfNew(bool marked[], int n)
{
    // Main logic of Sundaram. Mark all numbers of the
    // form i + j + 2ij as true where 1 <= i <= j
    for (int i = 1; i <= n; i++)
        for (int j = i; (i + j + 2 * i * j) <= n; j++)
            marked[i + j + 2 * i * j] = true;
}

void solve(int n)
{
    // In general Sieve of Sundaram, produces primes smaller
    // than (2*x + 2) for a number given number x.
    // Since we want primes smaller than n, we reduce n to half
    int newN = (n - 2) / 2;

    // This array is used to separate numbers of the form i+j+2ij
    // from others where 1 <= i <= j
    bool marked[newN + 1];

    // Initialize all elements as not marked
    memset(marked, false, sizeof(marked));

    SieveOfNew(marked, newN);
    // if n > 2 then 2 is also a circular prime
    cout << "2 ";

    // According to Sieve of sundaram If marked[i] is false
    // then 2*i + 1 is a prime number.

    // loop to check all  prime numbers and their rotations
    for (int i = 1; i <= newN; i++)
    {
        // Skip this number if not prime
        if (marked[i] == true)
            continue;

        int num = 2 * i + 1;
        num = Rotate(num); // function for rotation of prime

        // now we check for rotations of this prime number
        // if new rotation is prime check next rotation,
        // till new rotation becomes the actual prime number
        // and if new rotation if not prime then break
        while (num != 2 * i + 1)
        {
            if (num % 2 == 0) // check for even
                break;

            // if rotated number is prime then rotate
            // for next
            if (marked[(num - 1) / 2] == false)
                num = Rotate(num);
            else
                break;
        }

        // if checked number is circular prime print it
        if (num == (2 * i + 1))
            cout << num << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}