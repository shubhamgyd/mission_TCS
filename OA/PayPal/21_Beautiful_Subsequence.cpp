/*
Given a string s of length n containing only letters 'a' and 'b'.
Find the lexicographically smallest subsequence of s of length k having atleast x number of 'b' .
Example Input: n=6, k=4, x=2 , s=aababb
Example Output: aabb
Constraints for n: [1,1e5]
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int x, k;
    cin >> x >> k;
    vector<int> v;
    int a = 0;
    for (auto it : str)
    {
        if (it == 'a')
            a++;
    }
    int min_bs = a >= k - x ? x : k - a;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == 'b')
        {
            v.push_back(i);
        }
        if (v.size() == min_bs)
            break;
    }
    reverse(begin(v), end(v));
    int j = 0;
    string ans = "";
    int a_min = k - v.size();
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'b')
        {
            if (i == v[j])
            {
                ans += str[v[j++]];
            }
        }
        else
        {
            if (!a_min)
                continue;
            ans += 'a';
            a_min--;
        }
        if (ans.length() == k)
            break;
    }
    cout << ans << endl;
    return 0;
}