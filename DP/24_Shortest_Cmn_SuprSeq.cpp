// Returning the shortest common supersequence
#include<bits/stdc++.h>
using namespace std;

string ShortLCS(string X,string Y,int row,int col)
{
    int dp[row+1][col+1];
    dp[0][0]=0;
    for(int i=1;i<=row;i++)
    {
        dp[i][0]=i;
    }
    for(int j=1;j<=col;j++)
    {
           dp[0][j]=j; 
    }

    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    int i=row,j=col;
    string str="";
    while(i>0 && j>0)
    {
        // If chars of both string same then fill it in new string and decreases its size by one each
        if(X[i-1]==Y[j-1])
        {
            str.push_back(X[i-1]);
            i--;
            j--;
        }
        else
        {
            // If row + col-1 > row-1+col  means ek row same row ke pichla block and current  block ka 
            // upper block
            if(dp[i][j-1]>dp[i-1][j])
            {
                str.push_back(X[i-1]);
                i--;
            }
            else
            {
                str.push_back(Y[j-1]);
                //j--;
                j--;
            }
        }
    }
    // If any uncommon chars remain in original string then fill it , until its length become zero
    while(i>0)
    {
        str.push_back(X[i-1]);
        i--;
    }
    while(j>0)
    {
        str.push_back(Y[j-1]);
        j--;
    }
    reverse(str.begin(),str.end());
    return str;
    
}



// If we want to find the only length , then we have to find the lcs of both string and return (m+n-lcs(s1,s2));
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string X="alex";
    string Y="lovesleetocode";
    int m=X.length();
    int n=Y.length();
    // Another way to find out length of super sequence : len(s1) + len(s2) - len(longest common sub seq)
    // You can find length of longest common su seq from previus que.
    string super_seq=ShortLCS(X,Y,m,n);
    cout<<"Shortest Common SuperSequence: "<<super_seq<<" And its length is :"<<super_seq.length()<<'\n';
    return 0;
}