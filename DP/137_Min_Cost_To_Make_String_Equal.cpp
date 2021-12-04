/*
Given two strings X and Y consisting of only digits ‘0’ to ‘9’. Find minimum cost required to
make the given two strings identical. Only operation allowed is to delete characters from any 
of the string. The cost of operation of deleting the digit ‘d’ is d units. 
 

Input:  X = 3759, Y = 9350
Output: 23
Explanation
For making both string identical, delete
characters 3, 7, 5 from first string and
delete characters 3, 5, 0 from second 
string. Total cost of operation is
3 + 7 + 5 + 3 + 5 + 0 = 23

Input:  X = 3198, Y = 98
Output: 4
*/



#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long



int LCS(string s1,string s2)
{
    int n=s1.length();
    int m=s2.length();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+2*(s1[i-1]-'0');
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
// Time Complexity :O(s1*s2)
// Space Complexity: O(s1*s2)


int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    string s1,s2;
    cin>>s1>>s2;
    int sum=0;
    for(int i=0;i<s1.length();i++)
    {
        sum+=s1[i]-'0';
    }

    for(int i=0;i<s2.length();i++)
    {
        sum+=s2[i]-'0';
    }

    cout<<sum-LCS(s1,s2)<<endl;
    return 0;

}