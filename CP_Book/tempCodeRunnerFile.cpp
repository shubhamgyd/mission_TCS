#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

bool checkPrime(int n)
{

    if (n < 2)
    {
        return false;
    }
    else if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }

    return true;
}

int SumOfPrimeDivisors(int n)
{

    long long int range = (long long int)sqrt(n);
    int sum = 0;

    for (int i = 1; i <= range; i++)
    {
        if (n % i == 0)
        {

            if (i == n / i && checkPrime(i))
            {
                sum += i;
            }
            else
            {

                if (checkPrime(i))
                {
                    sum += i;
                }
                if (checkPrime(n / i))
                {
                    sum += (n / i);
                }
            }
        }
    }

    return sum;
}

int arrayDivision(int N, int K, vector<int> A)
{
    vector<int> temp;
    for (int i = 1; i < N; i++)
    {
        temp.push_back(A[i - 1] - A[i]);
    }
    sort(temp.begin(), temp.end());
    int ans = A[N - 1] - A[0];
    for (int i = 0; i < K - 1; ++i)
    {

        ans += temp[i];
    }
    return ans;
}

int32_t main()
{
    const int MOD = 1e9 + 7;
    int A, B;
    cin >> A >> B;
    long ans = 1;
    long total = 1;
    for (int i = 2; i <= A; i++)
    {
        long temp = (ans * B);
        cout << temp << endl;
        ans = temp;
        total = (total + temp) % MOD;
    }
    int res = (total * (B - 1)) % MOD;
    // cout<<res<<endl;
    cout << res << endl;
    return 0;
}