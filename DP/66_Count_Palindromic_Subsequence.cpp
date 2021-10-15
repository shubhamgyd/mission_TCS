#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       long long int MOD=1000000007;
       int n=str.length();
       int dp[1001][1001];
       memset(dp,0,sizeof(dp));
       for(int i=0;i<n;i++)
       {
           dp[i][i]=1;
       }
       for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n-L; i++) {
            int k = L + i - 1;
            if (str[i] == str[k])
                dp[i][k]= dp[i][k - 1]%MOD + dp[i + 1][k]%MOD + 1;
            else
                dp[i][k] = dp[i][k - 1]%MOD + dp[i + 1][k]-dp[i + 1][k - 1]%MOD;
        }
    }

    // return total palindromic subsequence
    return dp[0][n - 1]%MOD;
       
       
    }
     
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  


/*
Alternative Solution
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
    string str;
    cin>>str;
    int n=str.length();
    
    int dp[n][n];
    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            if(gap==0)
            {
                dp[i][j]=1;
            }
            else if(gap==1)
            {
                dp[i][j]=str[i]==str[j]?3:2;
            }
            else
            {
                if(str[i]==str[j])
                {
                    dp[i][j]=dp[i+1][j]+dp[i][j-1]+1;
                }
                else
                {
                    dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}

*/








// Recursion
#include<bits/stdc++.h>
using namespace std;


int CountPalindrome(string str,int i,int j)
{
    // Base condition 
    if(i>j)
    {
        return 0;
    }
    if(i==j)
    {
        return 1;
    }
    
    // We have two choices , either take it or leave it
    else if(str[i]==str[j])
    {
        return CountPalindrome(str,i,j-1)+CountPalindrome(str,i+1,j)+1;
    }

    // Here two times palindrome string is forming , so we have to minus one
    else
    {
        return CountPalindrome(str,i,j-1)+CountPalindrome(str,i+1,j)-CountPalindrome(str,i+1,j-1);
    }
}
// Time Complexity :Exponential






// Memoization : Top Down DP
int dp[501][501];
int CountPalindromes(string str,int i,int j)
{
    // Base condition 
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(i==j)
    {
        return dp[i][j]=1;
    }
    
    // We have two choices , either take it or leave it
    else if(str[i]==str[j])
    {
        return dp[i][j]=CountPalindrome(str,i,j-1)+CountPalindrome(str,i+1,j)+1;
    }

    // Here two times palindrome string is forming , so we have to munus one
    else
    {
        return dp[i][j]=CountPalindrome(str,i,j-1)+CountPalindrome(str,i+1,j)-CountPalindrome(str,i+1,j-1);
    }
}

int main()
{
    string str;
    cin>>str;
    int n=str.length();
    memset(dp,-1,sizeof(dp));
    cout<<CountPalindromes(str,0,n-1)<<endl;
    return 0;
}