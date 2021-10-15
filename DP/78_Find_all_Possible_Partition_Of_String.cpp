#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>>ans;
    void solve(string str,string res,int n)
    {
        for(int i=1;i<=n;i++)
        {
            string x=str.substr(0,i);                //-->// Substring of length i
            string y=string(x.rbegin(),x.rend());    //-->// Reversing the substring
                if(y==x)                             //-->//  if is palindrome
                {
                    if(i==n)                         //-->// if length length of substring is equal to length of string
                    {
                        vector<string>v;
                        v.push_back(res+x);         // updating the result
                        ans.push_back(v);
                        return;
                    }
                    solve(str.substr(i),res+x+" ",n-x.length());        // Recurive function of remaining length and substring of original string
                }
        }
    }
  public:
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        string res="";
        int n=S.length();
        solve(S,res,n);
        return ans;
    }
};