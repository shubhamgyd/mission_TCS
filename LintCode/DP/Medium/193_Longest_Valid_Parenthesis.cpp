/*
Description
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example
Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring

*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str;
    cin>>str;
    int n=str.length();

    // Solution 1: Brute Force
    int mx=0;
    for(int len=1;len<n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            int j=i+len-1;
            int open=0;
            int close=0;
            for(int k=i;k<=j;k++)
            {
                if(str[k]=='(') open++;
                else close++;
            }

            if(open==close)
            {
                mx=max(mx,2*close);
            }
        }
    }
    // Time Complexity:O(n^3)
    // Space Complxity:O(1)
    cout<<mx<<endl;



    // int ans=solve()



    
}