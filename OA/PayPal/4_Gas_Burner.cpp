#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = 1e9 + 7;

int solve(vector<int> &X, int K, int N)
{
    sort(X.begin(), X.end(), greater<int>());
    ll s = 0, a = 0, c = 1;
    for (int i = K; i < N; i++)
        s += X[i];
    for (int i = K - 1; i > 0; i--)
    {
        if (s >= c * (X[i - 1] - X[i]))
        {
            s -= c * (X[i - 1] - X[i]);
            c++;
            a = X[i - 1];
        }
        else
        {
            a += s / c;
            s = 0;
            break;
        }
    }
    if (s > 0)
        a += s / c;

    return a;
}

int main()
{
}