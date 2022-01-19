/*
This problem was asked by Microsoft.

Given a dictionary of words and a string made up of those words (no spaces), return the 
original sentence in a list. If there is more than one possible reconstruction, 
return any of them. If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string 
"thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string 
"bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string A, vector<string>& B) {
        int size=A.length();
        if(size==0)
        {
            return true;
        }
        for(int i=1;i<=A.length();i++)
        {
            if(find(B.begin(),B.end(),A.substr(0,i))!=B.end() && 
                    wordBreak(A.substr(i,size-i),B))
                    {
                        return true;
                    }
        }
        return false;
    }
};



int solve(string s,vector<string>&res)
{
    unordered_set<string>st;
    for(auto it:res)
    {
        st.insert(it);
    }
    int size=s.length();
    if(res.size()==0)
    {
        return false;
    }
    vector<bool>dp(size+1,0);
    dp[0]=true;
    for(int i=1;i<=size;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            string str=s.substr(j,i-j);
            if(st.find(str)!=st.end())
            {
                dp[i]=true;
                break;
            }
        }
    }
    return dp[size];
}


bool solve1(string s,vector<string>&res)
{
    int size=s.length();
    if(res.size()==0)
    {
        return false;
    }

    vector<bool>dp(size+1,false);
    dp[0]=true;
    // we mark as true every index that we managed to segment so far
        for (int i = 1; i <= s.size(); i++)
            for (int j = 0; j < i; j++)
                if ((dp[j]) && (find(res.begin(), res.end(), s.substr(j, i-j)) != res.end())) {
                    dp[i] = true;
                    break;
                }
        return dp.back();

}
// Time Complexity:O(n^3)
// Space Complexity:O(n)

