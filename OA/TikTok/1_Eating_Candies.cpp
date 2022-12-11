/*
There are n candies put from left to right on a table. The candies are numbered from left to right. The i-th candy has weight wi. Alice and Bob eat candies. Alice can eat any number of candies from the left (she can't skip candies, she eats them in a row). Bob can eat any number of candies from the right (he can't skip candies, he eats them in a row). Of course, if Alice ate a candy, Bob can't eat it (and vice versa).

They want to be fair. Their goal is to eat the same total weight of candies, What is the most number of candies they can eat in total?

Example

candies:[1000]

There is only candy, and it is not possible for Alice and Bob to eat the same total weight. So the function should return 0

Example

candies:[1,2,1] Alice takes 1 candy from the left and Bob takes 1 candy

from the right

So the function should return 2
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int suff[n];
    suff[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1] + arr[i];
    }
    reverse(suff, suff + n);
    int i = 0;
    int sum = 0;
    int mxWeight = 0;
    while (i < n)
    {
        sum += arr[i];
        int aliceCount = i + 1;
        bool isFind = binary_search(suff, suff + n, sum);
        if (isFind)
        {
            int bobCount = lower_bound(suff, suff + n, sum) - suff;
            bobCount++;
            if (aliceCount + bobCount <= n)
            {
                mxWeight = max(mxWeight, aliceCount + bobCount);
            }
        }
        i++;
    }
    cout << mxWeight << endl;
    return 0;
}