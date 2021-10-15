// PRinting longest common subsequence form the given two strings
#include<bits/stdc++.h>
using namespace std;

string LCS(string X,string Y,int m,int n)
{
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            // Filling up the whole matrix 
            if(X[i-1]==Y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int i=m,j=n;
    string s="";
    //vector<string>s;
    while(i>0 &&j>0)
    {
        // If the both strings character matched then , push this char into the new str 
        // and go one  row and column behind to check further characters.
        //i.e. upper left cross block
        if(X[i-1]==Y[j-1])
        {
            s.push_back(X[i-1]);
            i--;
            j--;
        }
        else
        {
            // If character of respective row nad column doesn't match
            // i.e row-1 > column-1 then ...iterate column one block behind i.e. j--
            // ultimately row number will remains same ..we have to just go back one step behind in column
            if(dp[i][j-1]>dp[i-1][j])  
            {
                j--;
            }
            // otherwise decrease the row number
            else
            {
                i--;
            }
        }
    }
    //We want to reverse given string , so that we will get alphabetical/sequential string
    return string(s.rbegin(),s.rend());  
    //return s;
}

bool isPalindrome(string s)
{
    int i=0;
    int j=s.length()-1;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string X="abb";
    // string Y=string(X.rbegin(),X.rend());
    string Y="abab";
    int m=X.length();
    int n=Y.length();
    string str=LCS(X,Y,m,n);


    cout<<str<<endl;


    // string temp=X;
    // std::string::size_type i = X.find(str);

    // if (i != std::string::npos)
    //     X.erase(i, str.length());
    

    // str=X;
    // string new_s1=temp+str;
    // string new_s2=Y+str;
    // if(isPalindrome(new_s1))
    // {
    //     cout<<new_s1<<endl;
    // }
    // else if(isPalindrome(new_s2))
    // {
    //     cout<<new_s2<<endl;
    // }
    return 0;
}