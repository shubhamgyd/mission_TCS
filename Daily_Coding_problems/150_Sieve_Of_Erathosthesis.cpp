/*
This problem was asked by Square.

The Sieve of Eratosthenes is an algorithm used to generate all prime numbers smaller than N. 
The method is to take increasingly larger prime numbers, and mark their multiples as composite.

For example, to find all primes less than 100, we would first mark [4, 6, 8, ...] (multiples of two), 
then [6, 9, 12, ...] (multiples of three), and so on. Once we have done this for all primes less than N, 
the unmarked numbers that remain will be prime.

Implement this algorithm.

Bonus: Create a generator that produces primes indefinitely (that is, without taking N as an input).
*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
public:

    void primeGenerator()
    {
    //     vector<char> is_prime(n+1, true);
    // is_prime[0] = is_prime[1] = false;
    // for (int i = 2; i * i <= n; i++) {
    //     if (is_prime[i]) {
    //         for (int j = i * i; j <= n; j += i)
    //             is_prime[j] = false;
    //     }
    // }
        vector<bool>isPrime(100000,true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i*i<=100000;i++)
        {
            if(isPrime[i])
            {
                for(int j=i*i;j<=100000;j+=i)
                {
                    isPrime[j]=false;
                }
            }
        }
        for(int i=2;i<=100000;i++)
        {
            if(isPrime[i])
            {
                cout<<i<<" ";
            }
        }
    }
};

int main()
{
    Solution obj;
    obj.primeGenerator();
    return 0;
}