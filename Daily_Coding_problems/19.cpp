/*

This question is asked by Facebook. Given a string and the ability to delete at most one character, 
return whether or not it can form a palindrome.
Note: a palindrome is a sequence of characters that reads the same forwards and backwards.

Ex: Given the following strings...

"abcba", return true
"foobof", return true (remove the first 'o', the second 'o', or 'b')
"abccab", return false

*/


#include<bits/stdc++.h>
using namespace std;

// if(j-i>1 && ( str[i+1]==str[j] || str[j-1]==str[i]))
//             {

//             }


bool solve(string str)
{
    int n=str.length();
    int i=0;
    int j=n-1;
    bool ok=true;
    int ct=0;
    while(i<=j)
    {
        if(str[i]!=str[j])
        {
            ok=false;
            ct++;
        }
        i++;
        j--;
    }
    if(ok)
    {
        // cout<<"H"<<endl;
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            // cout<<"H"<<endl;
            bool ok=true;
            int j=1;
            int k=n-1;
            while(j<=k)
            {
                if(str[j]!=str[k])
                {
                    ok=false;
                    break;
                }
                j++;
                k--;
            }
            if(ok)
            {
                return true;
            }
        }
        else
        {
            bool ok=true;
            int j=0;
            int k=n-1;
            while(j<=k)
            {
                if(j==i)
                {
                    j++;
                }
                if(k==i)
                {
                    k--;
                }
                if(str[j]!=str[k])
                {
                    ok=false;
                    break;
                }
                j++;
                k--;
            }
            if(ok)
            {
                return true;
            }
        }
    }
    return false;
}
// Time Complexity:O(|s|*|s-1|)
// Space Complexity:O(1)




// Optimise
bool solve1(string str)
{
    int n=str.length();
    int i=0;
    int j=n-1;
    int ct=0;
    bool ok=false;
    while(i<=j)
    {
        if(str[i]!=str[j] && j-i>1 && (str[i+1]==str[j] || str[j-1]==str[i]))
        {
            cout<<str[i]<<" "<<str[j]<<endl;
            if(str[i+1]==str[j])
            {
                ct++;
                i+=2;
                j--;
            }
            else if(str[j-1]==str[i])
            {
                ct++;
                j-=2;
                i++;
            }
            else if(str[i]!=str[j-1] && str[j]!=str[i+1])
            {
                ct++;
                return false;
            }
            
        }
        else if(str[i]!=str[j] && j-i==1)
        {
            ct++;
            i++;
            j--;
        }
        else
        {
            i++;
            j--;
        }
    }
    if(ct>1)
    {
        return false;
    }
    return true;
}
// Time Complexity:O(|s|)
// Space Complexity:o(1)



// DP solution
// This is problem of min deletion to make the string palindrome, see all it's solution
int Deletion(string str)
{
    string s=str;
    reverse(s.begin(),s.end());
    int n=str.length();
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            // Increase the LCS by 1
            if(str[i-1]==s[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }

            // if not matched then, take the preious max length
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j]);
            }
        }
    }
    // return max lcs length
    return dp[n][n];
}
// Time Complexity:O(|s|*|s|)
// Space Complexity:O(|s|*|s|)



int main()
{
    string str;
    cin>>str;
    int n=str.length();
    bool temp=solve(str);
    bool temp1=solve1(str);
    if(temp)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    if(temp1)
    {
        cout<<"True"<<endl;
    }
    else if(temp1==false)
    {
        cout<<"False"<<endl;
    }
    int count=Deletion(str);
    int result=n-count;
    if(result<=1)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;
}