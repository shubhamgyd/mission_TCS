/*
This question is asked by Facebook. Given a string s containing only 
lowercase letters, continuously remove adjacent characters that are 
the same and return the result.

Ex: Given the following strings...

s = "abccba", return ""
s = "foobar", return "fbar"
s = "abccbefggfe", return "a"

https://practice.geeksforgeeks.org/viewSol.php?subId=38c440d087941cb5da48c6fe50673ac6&pid=705889&user=nilesh1206
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    stack<char>st;
    for(char ch:str)
    {
        // cout<<"H"<<endl;
        if(!st.empty() && st.top()==ch)
        {
            while( !st.empty() && st.top()==ch)
            {
                st.pop();
            }
            // continue;
        }
        else
        {
            st.push(ch);
        }
    }
    cout<<st.empty()<<endl;
    string ans="";
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}
// Time Complexity :O(|s|*|s|)
// Space Complexity:O(|s|)