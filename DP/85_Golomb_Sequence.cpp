/*
In mathematics, the Golomb sequence is a non-decreasing integer sequence where n-th term is equal 
to number of times n appears in the sequence.
The first few values are 
1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, ……
Explanation of few terms: 
Third term is 2, note that three appears 2 times. 
Second term is 2, note that two appears 2 times. 
Fourth term is 3, note that four appears 3 times.
Given a positive integer n. The task is to find the first n terms of Golomb sequence. 
Examples : 
 

Input : n = 4
Output : 1 2 2 3

Input : n = 6
Output : 1 2 2 3 3 4
*/


// Recursive Approach
#include<bits/stdc++.h>
using namespace std;

int Golomb(int n)
{
    // Base Case
    if(n==1)
    {
        return 1;
    }

    return 1+Golomb(n-Golomb(Golomb(n-1)));
}

void Golomb1(int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<Golomb(i)<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    Golomb1(n);
    return 0;
}
// Time complexity is very high



// DP Solution
#include<bits/stdc++.h>
using namespace std;


void solve(int n)
{
    int dp[n+1];
    dp[1]=1;
    cout<<dp[1]<<" ";

    for(int i=2;i<=n;i++)
    {
        dp[i]=1+dp[i-dp[dp[i-1]]];
        cout<<dp[i]<<" ";
    }
    return;
}

int  main()
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity:O(n)
*/