#include <bits/stdc++.h>
using namespace std;

int modpow(int x, int N)
{
    int mod = 1e9 + 7;
    if (N == 0)
        return 1;
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;

    long long a = 1LL * modpow(x, N / 2);
    a = (1LL * a * a) % mod;
    if (N & 1)
        a *= x;

    a %= mod;
    return (int)(a % mod);
}

int find_min_product(int N)
{
    int mod = 1e9 + 7;
    int a = N / 2;
    return (1LL * N * modpow(N - 1, a)) % mod;
}

int main()
{
}