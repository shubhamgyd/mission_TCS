/*
Given a string S, we can split S into 2 strings: S1 and S2. Return the number of ways S 
can be split such that the number of unique characters between S1 and S2 are the same.

Example 1:

Input: "aaaa"
Output: 3
Explanation: we can get a - aaa, aa - aa, aaa- a
Example 2:

Input: "bac"
Output: 0
Example 3:

Input: "ababa"
Output: 2
Explanation: ab - aba, aba - ba
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int n=str.size();
    // Brute Force
    int cnt=0;
    set<char>prev;
    for(int i=0;i<n;i++)
    {
        prev.insert(str[i]);
        set<char>after;
        for(int j=i+1;j<n;j++)
        {
            after.insert(str[j]);
        }
        if(prev.size()==after.size())
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    // Time Complexity:O(n*n)
    // Space Complexity:O(n)


    // Optimize
    set<char>st;
    int pref[n];
    int suff[n];
    memset(pref,0,sizeof(pref));
    memset(suff,0,sizeof(suff));
    for(int i=0;i<n;i++)
    {
        st.insert(str[i]);
        pref[i]=st.size();
    }
    st.clear();
    for(int i=n-1;i>=0;i--)
    {
        st.insert(str[i]);
        suff[i]=st.size();
    }
    cnt=0;
    for(int i=0;i<n-1;i++)
    {
        if(pref[i]==suff[i+1])
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
}