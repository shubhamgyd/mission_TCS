/*
Question 2 - The minimum possible cost of shipping
Amazon ships millions of packages regularly. There are a number of parcels that need to
be shipped. Compute the minimum possible sum of transportation costs incurred in the
shipment of additional parcels in the following scenario.

A fully loaded truck carries k parcels.
It is most efficient for the truck to be fully loaded.
There are a number of parcels already on the truck as listed in parcels[].
There are parcels with a unique id that ranges from 1 through infinity.
The parcel id is also the cost to ship that parcel.
Given the parcel IDs which are already added in the shipment, find the minimum
possible cost of shipping the items added to complete the load.

Example
parcels = [2, 3, 6, 10, 11]
k = 9

Parcel ids range from 1 through infinity. After reviewing the current manifest,
the remaining parcels to choose from are [1, 4, 5, 7, 8, 9, 12, 13, ...].
There are 5 parcels already on the truck, and it can carry k = 9 parcels when fully loaded.
Choose 4 more packages to include: [1, 4, 5, 7]. Their shipping cost is 1 + 4 + 5 + 7 = 17,
 which is minimal. Return 17.

Constraints

1 ≤ n ≤ 2 · 105
1 ≤ parcels[i] ≤ 106
n ≤ k ≤ 106
Input Format For Custom Testing

The first line contains an integer, n, the size of parcels.
Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer, parcels[i].
The last line contains the integer k, the capacity of the truck.
Sample Case 0
Sample Input For Custom Testing

STDIN
5
6
5
4
1
3
7

parcels[] size n = 5
parcels = [6, 5, 4, 1, 3]
k = 7

Sample Output
9

Explanation
The shipment already has 5 parcels and needs 2 more. The parcels [2, 7] can be added
to have the shipment of exactly 7 parcels, [1, 2, 3, 4, 5, 6, 7]. The additional cost
is 2 + 7 = 9.

Sample Case 1
Sample Input For Custom Testing

STDIN

4
4
5
7
1
4

parcels[] size n = 4
parcels = [4, 5, 7, 1]
k = 4

Sample Output
0

Explanation
The truck is already filled to capacity.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    bool arr[1000001] = {0};
    for (int i = 0; i < n; i++)
    {
        arr[nums[i]] = 1;
    }
    int cnt = 0;
    for (int i = 1, track = 0; i <= 1000000 and track < k - n; i++)
    {
        if (!arr[i])
        {
            cnt += i;
            track++;
        }
    }
    cout << cnt << endl;
    return 0;
}
/*
Time Complexity:O(rem-k)
Space Complexity:O(n)
*/