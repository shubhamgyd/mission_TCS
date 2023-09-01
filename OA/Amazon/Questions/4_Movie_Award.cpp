/*
Amazon Prime Video is a subscription video-on-demand over-the-top streaming and rental service. The team at Prime Video is developing a method to divide movies into groups based on the number of owards they have won. A group can consist of any number of movies, but the difference in the number of awards won by any two movies in the group must not exceed k

The movies can be grouped together irrespective of their initial order. Determine the minimum number of groups that can be formed such that each movie is in exactly one group

Example

The numbers of awards per movie are awards= [1, 5, 4, 6, 8, 9, 21 and the maximum allowed difference is k = 3.

One way to divide the movies into the minimum number of groups is:

• The first group can contain 12. 11. The maximum difference between awards of any two movies is which does not exceed k •The second group can contain 15. 4. 61 The maximum difference between awards of

any two movies is 2 which does not exceed

The third group can contain 18. 91. The maximum difference between awards of any

two movies is 1 which does not exceed

The movies can be divided into a minimum of 3 groups
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
    int k;
    cin >> k;
    sort(arr, arr + n);
    int start = arr[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - start > k)
        {
            cnt++;
            start = arr[i];
        }
    }
    cout << cnt << endl;
    return 0;
}