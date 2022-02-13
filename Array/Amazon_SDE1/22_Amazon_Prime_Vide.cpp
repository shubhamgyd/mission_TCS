/*
Amazon Prime Video is a subscription video-on-demand over-the-top streaming and rental service. The team at Prime Video is developing a method to divide movies into groups based on the number of awards they have won. A group can consist of any number of movies, but the difference in the number of awards won by any two movies in the group must not exceed k.
The movies can be grouped together irrespective of their initial order. Determine the minimum number of groups that can be formed such that each movie is in exactly orly group.
Example
The numbers of awards per movie are awards = [1, 5, 4, 6, 8, 9, 21, and the maximum allowed difference is k = 3.

One way to divide the movies into the minimum number of groups is:

The first group can contain [2, 1], The maximum difference between awards of any two movies is 1 which does not exceed K.
The second group can contain [5, 4, 6], The maximum difference between awards of any two movies is 2 which does not exceed k.
The third group can contain [8,9]. The maximum difference between awards of any two movies is 1 which does not exceed k.
The movies can be divided into a minimum of 3 groups.

Function Description
Complete the function minimumGroups in the
editor below.
minimum Groups has the following parameters:
int awards[n]; the number of awards each movie has earned
int k: the maximum difference in awards counts
*/

/*


def closestElements(self,arr:List[int],avg:int)-> List[List[int]]:
        arr.sort()
        res = [[arr[0]]]

        for x in arr[1:]:
            if x - res[-1][0] < avg:
                res[-1].append(x)
            else:
                res.append([x])
        return res
*/

#include <bits/stdc++.h>
using namespace std;

int closestelement(int k, vector<int> arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    sort(arr.begin(), arr.end());
    int count = 1;
    int lower = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - lower < k)
            continue;
        else
        {
            lower = arr[i];
            count++;
        }
    }
    return count;
}
// Time Complexity:O(n)
// Space Complexity:O(1)

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    int k;
    cin >> k;
    sort(res.begin(), res.end());
    vector<vector<int>> ans;
    ans.push_back({res[0]});

    for (int i = 1; i < n; i++)
    {
        if (res[i] - ans.back()[0] < k)
        {
            ans.back().push_back(res[i]);
        }
        else
        {
            ans.push_back({res[i]});
        }
    }
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}