#include<bits/stdc++.h>
using namespace std;

// bool isPrime(int n)
// {
//     // Corner cases
//     if (n <= 1)
//         return false;
//     if (n <= 3)
//         return true;
 
//     // This is checked so that we can skip
//     // middle five numbers in below loop
//     if (n % 2 == 0 || n % 3 == 0)
//         return false;
 
//     for (int i = 5; i * i <= n; i = i + 6)
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
 
//     return true;
// }

int main()
{
    int n;
    cin>>n;
    vector<char> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<int>vc;
    int ct=0;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]==true)
        {
            vc.push_back(i);
        }
    }
    int sum=2;
    for(int i=1;i<vc.size();i++)
    {
        sum+=vc[i];
        if(sum<=n)
        {
            if(is_prime[sum])
            {
                ct++;
            }
        }
        else
        {
            break;
        }
    }
    cout<<ct<<endl;

    return 0;
}