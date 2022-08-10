/*
Given a string, s, that contains a valid set of parentheses, return the maximum depth of the parentheses seen at any point of the string.
Note: For example, “abc”, “()”, and “(()), have depths of zero, one, and two respectively.

Ex: Give the following string s…

s = "The(Daily)Byte", return 1.
Ex: Give the following string s…

s = ""The(Daily)Byte((Dot)Dev)"", return 2.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int mxDepth=0;
    int open=0;
    int close=0;
    for(int i=0;i<str.length();++i)
    {
        if(str[i]=='(') {
            open++;
            mxDepth=max(mxDepth,open);
        }

        else if(str[i]==')'){
            if(open>=0) open--;
            else{
                cout<<0<<endl;
                return 0;
            }
        }
    }
    cout<<mxDepth<<endl;
    return 0;
}