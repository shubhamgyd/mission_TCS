/*
integers, query values, return the 1-based index in the query values[i] occurrence of Xdoes not
occur query times, return for that query.

Example

X=8

query values(100, 4, 2)

There 100th instance

Function Description

kthOccurrence in editor.

kthOccurrence the

the integer search for

query values[q]: the occurrence find index of

Returns

int[q]: the arr for query
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int q;
    cin >> q;
    int query[q];
    for (int i = 0; i < q; ++i)
    {
        cin >> query[i];
    }
    vector<int> occurs;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            occurs.push_back(i + 1);
    }
    int ans[q];
    int size = occurs.size();
    for (int i = 0; i < q; ++i)
    {
        int times = query[i];
        if (times > size)
            ans[i] = -1;
        else
            ans[i] = occurs[times - 1];
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << " ";
    return 0;
}