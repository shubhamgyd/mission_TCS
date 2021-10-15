// cpp program to check if a string can
// be converted to another string by
// performing operations
#include <bits/stdc++.h>
using namespace std;

// function to check if a string can be
// converted to another string by
// performing following operations
bool check(string s1, string s2)
{
	// calculates length
	int n = s1.length();
	int m = s2.length();

	bool dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = false;
		}
	}
	// mark 1st position as true
	dp[0][0] = true;

	// traverse for all DPi, j
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j <= s2.length(); j++) {

			// if possible for to convert i
			// characters of s1 to j characters
			// of s2
			if (dp[i][j]) {

				// if upper_case(s1[i])==s2[j]
				// is same
				if (j < s2.length() &&
					(toupper(s1[i]) == s2[j]))
					dp[i + 1][j + 1] = true;

				// if not upper then deletion is
				// possible
				if (!isupper(s1[i]))
					dp[i + 1][j] = true;
			}
		}
	}

	return (dp[n][m]);
}

// driver code
int main()
{
	string s1 = "daBcd";
	string s2 = "ABC";

	if (check(s1, s2))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}





































#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long


string LCS(string str,string cmp)
{
    int n=str.length();
    int m=cmp.length();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str[i-1]==cmp[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    string s="";
    int i=n;
    int j=m;
    while(i>0 && j>0)
    {
        if(str[i-1]==cmp[j-1])
        {
            s.push_back(str[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return string(s.rbegin(),s.rend());
}


int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    string str,cmp;
    cin>>str>>cmp;
    string temp=str;
    int n=str.length();
    int m=cmp.length();
    map<char,int>mp;
    for(auto ch:cmp)
    {
        mp[ch]++;
    }
    for(int i=0;i<str.length();i++)
    {
        char ele=toupper(str[i]);
        if(mp.find(ele)!=mp.end())
        {
            str[i]=ele;
        }
    }
    string res=LCS(str,cmp);
    cout<<res<<endl;
    if(res==cmp)
    {
        int i=0;
        int j=0;
        while(i<n && j<m)
        {
            if(str[i]==cmp[j])
            {
                str[i]='-';
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        int flag=0;

        // cout<<str<<endl;
        for(i=0;i<n;i++)
        {   
            if(str[i]=='-')
            {
                continue;
            }
            else if(isupper(str[i]) && isupper(temp[i]))
            {
                flag=1;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"YES"<<endl;
        }


    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}