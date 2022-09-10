/*

This problem was asked by Palantir.

The ancient Egyptians used to express fractions as a sum of several terms
where each numerator is one. For example, 4 / 13 can be represented as 1 / 4 + 1 / 18 + 1 / 468.

Create an algorithm to turn an ordinary fraction a / b, where a < b, into an Egyptian fraction.
*/

#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    if (s.size() <= 1) return s;
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int left = 0, len = 1;
    for (int i = 0; i < s.size(); i++)
    {
        dp[i][i] = true;
        if (i == s.size() - 1)
            break;
        dp[i][i + 1] = (s[i] == s[i + 1]);
        if (dp[i][i + 1] && len == 1)
        {
            left = i;
            len = 2;
        }
    }
    for (int i = s.size() - 3; i >= 0; i--)
    {
        for (int j = i + 2; j < s.size(); j++)
        {
            dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            if (dp[i][j] && (j - i + 1) > len)
            {
                len = j - i + 1;
                left = i;
            }
        }
    }
    return s.substr(left, len);
}


long long factorial(int n){
    long long res=1;
    for(int i=1; i<=n; i++){
        res*=i;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<(7+3.75)/3<<endl;
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}