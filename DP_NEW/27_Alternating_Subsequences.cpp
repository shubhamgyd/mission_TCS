/*
Recall that the sequence b is a a subsequence of the sequence a if b can be derived from a
by removing zero or more elements without changing the order of the remaining elements.
For example, if a=[1,2,1,3,1,2,1], then possible subsequences are: [1,1,1,1], [3] and 
[1,2,1,3,1,2,1], but not [3,2,3] and [1,1,1,1,2].

You are given a sequence a consisting of n positive and negative elements (there is no zeros 
in the sequence).

Your task is to choose maximum by size (length) alternating subsequence of the given sequence 
(i.e. the sign of each next element is the opposite from the sign of the current element, like 
positive-negative-positive and so on or negative-positive-negative and so on). Among all such 
subsequences, you have to choose one which has the maximum sum of elements.

In other words, if the maximum length of alternating subsequence is k then your task is to 
find the maximum sum of elements of some alternating subsequence of length k.

*/

#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int sum = 0;
        int i = 0;
        for (i = 0; i < n;)
        {
            if (arr[i] < 0)
            {
                int val = INT_MIN;
                while (arr[i] < 0 && i < n)
                {
                    val = max(val, arr[i]);
                    i++;
                }
                sum += val;
            }
            else if (arr[i] > 0)
            {
                int val = INT_MIN;
                while (arr[i] > 0 && i < n)
                {
                    val = max(val, arr[i]);
                    i++;
                }
                sum += val;
            }
        }
        cout << sum << endl;
    }
    return 0;
}