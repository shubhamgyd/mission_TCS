/*
We are given an array A. We have to find the number of pairs with following conditions

i<j
A[i]=A[j]
i*j is divisible by X
Have to do this in something better than O(N * N). I used an approach with hashmap to store all indices with condition 2 in one array, and that element as key, but that solution was not efficient enough. I think it has something to do with GCD. Any help is appreciated.

Sample input:
A: [ 2,3,4,3,3,2,3,3]
X: 2

Sample output:
10

eg:
(1,6)
(2,4)
(2,5)
(2,7)
(2,8)
(4,5)
(4,7)
(4,8)
(5,8)
(7,8)
*/

#include <bits/stdc++.h>
using namespace std;

void addDivisors(int n, map<int, int> &mp)
{
    int m = 1;
    while (m * m <= n)
    {
        if (n % m == 0)
        {
            mp[m] = mp[m] + 1;

            int l = n / m;
            if (l != m)
            {
                mp[l] = mp[l] + 1;
            }
        }
        m += 1;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int x;
    cin >> x;
    map<int, map<int, int>> mp;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[0])
        {
            ans++;
        }
        // Search
        if (mp.find(nums[i]) != mp.end())
        {
            int getM = x / (__gcd(x, i));
            ans += (mp[nums[i]][getM]);
            // Initialise this value's
            // search structure
        }
        else
        {
            mp[nums[i]] = map<int, int>();
        }
        //  Add divisors for j
        addDivisors(i, mp[nums[i]]);
    }
    cout << ans << endl;
    return 0;
}