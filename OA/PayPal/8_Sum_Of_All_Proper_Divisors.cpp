#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if ((n % i) == 0)
        {
            if (i == (n / i))
            {
                sum += i;
            }
            else
            {
                sum += (i + n / i);
            }
        }
    }
    sum += 1;
    if (sum == n)
    {
        cout << "Perfect\n";
    }
    else if (sum < n)
    {
        cout << "Deficient\n";
    }
    else
    {
        cout << "Abundant\n";
    }
    return 0;
}