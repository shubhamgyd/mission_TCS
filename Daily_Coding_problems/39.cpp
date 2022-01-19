/*
This problem was asked by Facebook.

Given a string of round, curly, and square open and closing brackets, 
return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.
*/

#include<bits/stdc++.h>
using namespace std;

bool NotPair(char opening ,char closing)
{
    if(opening=='(' &&  closing==')')
    {
        return true;
    }
    if(opening=='{' && closing=='}')
    {
        return true;
    }
    if(opening=='[' && closing==']')
    {
        return true;
    }
    return false;
}

int main()
{
    string str;
    cin>>str;
    stack<char>st;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='{' || str[i]=='(' || str[i]=='[')
        {
            st.push(str[i]);
        }
        else if(str[i]=='}' || str[i]==')' || str[i]==']')
        {
            if(st.empty() || !NotPair(st.top(),str[i]))
            {
                cout<<"Given Expression is not balanced"<<endl;
                return 0;
            }
            else
            {
                st.pop();
            }
        }
    }
    if(st.empty())
    {
        cout<<"Given Expression is balanced"<<endl;
    }
    else
    {
        cout<<"Given Expression is not balanced"<<endl;
    }
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(n)
// Where n is the length of the string