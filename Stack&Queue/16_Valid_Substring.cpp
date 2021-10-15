// In this problem we are going to find the valid substring of parenthesis

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxLen(string s) {
        // code here


        // Ans 1: Simple 


        
        // int ans=0;
        // int open=0;
        // int close=0;
        // for(int i=0;i<str.length();i++)
        // {
        //     if(str[i]=='(')
        //     {
        //         open++;
        //     }
        //     else
        //     {
        //         close++;
        //     }
        //     if(open==close)
        //     {
        //         ans=max(ans,2*open);
        //     }
        //     else if(close>open)
        //     {
        //         open=close=0;
        //     }
        // }
        // open=close=0;
        // for(int i=str.length()-1;i>=0;i--)
        // {
        //     if(str[i]=='(')
        //     {
        //         open++;
        //     }
        //     else
        //     {
        //         close++;
        //     }
        //     if(open==close)
        //     {
        //         ans=max(ans,2*open);
        //     }
        //     else if(open>close)
        //     {
        //         open=close=0;
        //     }
        // }
        // return ans;



        // Ans 2: Stack
        stack<int>st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i);
            else 
            {
                if (!st.empty())
                    st.pop();
        
                if (!st.empty())
                    ans = max(ans, i - st.top());
                else
                    st.push(i);
            }
        
        }

        return ans;
    }
};