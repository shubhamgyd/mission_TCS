/*
Given an array of integers A, find the length of largest triangular subsequence. A subsequence is called triangular if every triplet S[i],S[j],S[k] belonging to subsequence S satisfies triangle inequality for i<j<k.
Example Input: A=[4,5,4,10,4]
Example Output= 4
Explanation: [4,5,4,4] is largest valid triangular subsequence. In [4,5,4,10,4] , 4+4<10, so not valid.
Solution with one test case failing: (Please mention the one corner case in comments)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    vector<int>::iterator itr;
    for (int i = 0; i < n - 2; i++)
    {
        int k = v[i] + v[i + 1];
        itr = lower_bound(v.begin(), v.end(), k);
        int z = itr - v.begin();
        ans = max(ans, z - i);
    }
    cout << ans << endl;
}