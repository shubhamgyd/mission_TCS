// Without whitespaces

/*
Without Whitespaces

A program generates an output of an array of integers. The programmer forgot to 
separate the numbers with white-spaces. You have a string S of length N consisting 
of non-negative integers. All the integers were not greater than C without leading 
zeroes. Write a program to find how many arrays could have S as an output? The answer 
can be very large, print it as modulo10^k.

Input Format
The first line contains 3 space-separeted integers: N, C, and K.
The second line contains a string S of length N.

Output Format
Output the answer modulo 10^k.

Input Constraints
1 <= N <= 100000
1 <= C <= 10^9
1 <= k <= 18

Sample Input
7 1234567 9
1234567

Sample Output
64
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,c,k;
    cin>>n>>c>>k;
    string str;
    cin>>str;
    int dp[n+1];
    const int mx=pow(10,k);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(int j=i-1;j>=0;j--)
        {
            string s=str.substr(j,i-j);
            int x=stoi(s);
            if(s[0]!='0' && x<=c)
            {
                dp[i]=(dp[i]+dp[j])%mx;
            }
            else if(x>c)
            {
                break;
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
// Time Complexity:O(n^2)
// Space Complexity:O(n)
